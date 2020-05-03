#include "opcn2.h"
#include "crpigpio.h"
#include <QThread>
OPCN2::OPCN2(Crpigpio *ObjectCrPigpio,uint8_t SpiChan, bool SPIAux)
{
    RA_cGPIOOPC = ObjectCrPigpio;
    initialize(SpiChan,SPIAux);
}

OPCN2::~OPCN2()
{
    RA_cGPIOOPC->CloseSPI();
}


void OPCN2::initialize(uint8_t SpiChan, bool SPIAux)
{
    unsigned SPIFlags = 1 | (SPIAux<<8);// | 0b10010000100000000000;//| 9<<16;
    //SPIFlags = SPIFlags | 0x90000;
  //  if(SPIAux) SPIFlags = 1 | (SPIAux<<8) | 9<<16;
    RA_cGPIOOPC->OpenSPI(SpiChan,500000,SPIFlags);
    QThread::msleep(StartupDelayMs); // Startup delay ~1s seems to be required
    timerONLectura=new QTimer;
    connect(timerONLectura, SIGNAL(timeout()),this,SLOT(getData()));
    _SPIAux = SPIAux;
}

bool OPCN2::checkStatus()
{
    bool ok = false;
    uint8_t rsp = 0xf3; //SPI.transfer(CmdCheckStatus); // send cmd byte
    QThread::msleep(SPICmdDelayMs);
    if (rsp == 0xf3)
    {
        ok = true;
    }
    return ok;
}



void OPCN2::setFanAndLaserOn(bool *ok)
{
    char rsp0;
    char rsp1;
    char null=0x00;
   if(!_SPIAux)
   {
       char cmdLaserFanOnOff = 0x03;
        RA_cGPIOOPC->WriteAndReadSPI( &cmdLaserFanOnOff, &rsp0,1);// send cmd byte
        QThread::msleep(SPICmdDelayMs);
        RA_cGPIOOPC->WriteAndReadSPI(&null,&rsp1,1);// send cmd byte
    }
   else
   {
       char cmdLaserFanOnOff[2];
       cmdLaserFanOnOff [0] = 0x03;
       cmdLaserFanOnOff [1]= 0x80;
       RA_cGPIOOPC->WriteAndReadSPI( &cmdLaserFanOnOff[0], &rsp0,2);// send cmd byte
       QThread::msleep(SPICmdDelayMs);
       RA_cGPIOOPC->WriteAndReadSPI(&null,&rsp1,1);// send cmd byte
   }
    QThread::msleep(SPICmdDelayMs);
    if (ok != nullptr)
    {
        if ((rsp0 == 0xf3) && (rsp1 == 0x03))
        {
            *ok = true;
        }
        else
        {
            *ok = false;
        }
    }
}


void OPCN2::setFanAndLaserOff(bool *ok)
{
    /*SPI.beginTransaction(spiSettings_);
    digitalWrite(param_.spiCsPin,LOW);
    */
    char rsp0;
    char rsp1;
    if(!_SPIAux)
    {
    char null1=0x01;
    char cmdLaserFanOnOff = 0x03;
    RA_cGPIOOPC->WriteAndReadSPI( &cmdLaserFanOnOff, &rsp0,1);// send cmd byte
    QThread::msleep(SPICmdDelayMs);
    RA_cGPIOOPC->WriteAndReadSPI( &null1, &rsp1,1);  // set laser and fan off
    QThread::msleep(SPICmdDelayMs);
}
    else
    {
        char null1[2];
        null1[0]=0x00;
        null1[1]=0x80;
        char cmdLaserFanOnOff[2];
        cmdLaserFanOnOff[0]= 0x01;
        cmdLaserFanOnOff[1]= 0x80;
        RA_cGPIOOPC->WriteAndReadSPI( &cmdLaserFanOnOff[0], &rsp0,1);// send cmd byte
        QThread::msleep(SPICmdDelayMs);
        RA_cGPIOOPC->WriteAndReadSPI(&null1[0],&rsp1,1);// send cmd byte
    }
    if (ok != nullptr)
    {
        if ((rsp0 == 0xf3) && (rsp1 == 0x03))
        {
            *ok = true;
        }
        else
        {
            *ok = false;
        }
    }
}

OPCN2Data OPCN2::getHistogramData(bool *ok)
{
    uint8_t rsp[HistogramMessageSize];
    char rspchar[HistogramMessageSize];
    char cmdReadHistogramData=0x30;
    for (int i=0; i<HistogramMessageSize; i++)
    {
        RA_cGPIOOPC->WriteAndReadSPI( &cmdReadHistogramData, &rspchar[i],1);// send cmd byte
        rsp[i]=rspchar[i];
        if (i==0)
        {
            QThread::msleep(SPICmdDelayMs);
        }
        else
        {
            QThread::usleep(SPIValDelayUs);
        }

    }
    QThread::msleep(SPICmdDelayMs);
    if (ok != nullptr)
    {
        if (rsp[0] == 0xf3)
        {
            *ok = true;
        }
        else
        {
            *ok = false;
        }
    }

    return OPCN2Data(rsp);
}

void OPCN2::getData() //Emite una senal con los datos de PM1, PM2.5 y PM10
{
    if( _mode !=MODE_SLEEP)
    {
        bool ok=true;
        for(int i=0; i < 10; i++)
        {
            Data = getHistogramData(&ok);
             if(!ok) Data = getHistogramData(&ok);
             if(ok){ emit newData(Data.PM1,Data.PM2_5,Data.PM10); return;}
        }
    }
    else qDebug() << "Falla: Sensor en MODE_SLEEP";
}

void OPCN2::ModeActive(uint16_t miliseconds)
{
    timerONLectura->setInterval(miliseconds);
    timerONLectura->start();
    _mode = MODE_ACTIVE;
}

void OPCN2::ModePassive()
{
    timerONLectura->stop();
     _mode = MODE_PASSIVE;
}



