#include "racimoaire2.h"
#include "ui_racimoaire2.h"

RacimoAire2::RacimoAire2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RacimoAire2)
{
    ui->setupUi(this);
    TimeMuestreo =10000;
    RA_cGPIO = new Crpigpio;
    RA_cGPIO2 = new Crpigpio(false);
    RA_cGPIO3 = new Crpigpio(false);

    RA_cPMS = new PMS(RA_cGPIO,GPIOPMSSet, GPIOPMSReSet, GPIOPMSRX,TimeMuestreo);
    RA_cGPS = new GPS(RA_cGPIO, GPIOGPSRX, GPIOGPSPPS);
    RA_cOPC = new OPCN2(RA_cGPIO,0,0);
    RA_cBME280 = new Adafruit_BME280(RA_cGPIO,0x77);
    RA_cGADC = new ADS1115(RA_cGPIO2);
    RA_cCorriente = new Adafruit_INA219(RA_cGPIO3);
    _DataJson =new DataJson("uis-11","UIS-11","-73.12194","7.140129","/home/pi/RACIMOAIRE");

    Serial =new NextionRaspberrypi(RA_cGPIO,9600,15);
    nexInit(Serial);
    txt_temp = new NexText(Serial,0,9,"t7");
    txt_Presion = new NexText(Serial,0,10,"t8");
    txt_hum = new NexText(Serial,0,13,"t11");
    txt_longitud = new NexText(Serial,0,15,"t13");
    txt_latitud = new NexText(Serial,0,18,"t16");
    txt_Altitud = new NexText(Serial,0,19,"t17");
    txt_Fix = new NexText(Serial,0,17,"t15");
    txt_wifi = new NexText(Serial,0,20,"t18");
    txt_PM25_P = new NexText(Serial,0,25,"t23");
    txt_PM25_O = new NexText(Serial,0,29,"t27");
    txt_PM10_P = new NexText(Serial,0,26,"t24");
    txt_PM10_0 = new NexText(Serial,0,30,"t28");


    TimeMuestraPromedioBME = new QTimer;
    TimeMuestraPromedioBME->setInterval(TimeMuestreo/2);
    TimeMuestraPromedioBME->start();


    connect(TimeMuestraPromedioBME, &QTimer::timeout,this, &RacimoAire2::DataLogs);

    connect(RA_cGPS, &GPS::newData,this, &RacimoAire2::newDataGPS);
    connect(RA_cPMS, &PMS::newData,this, &RacimoAire2::newDataPMS);
    connect(RA_cPMS, &PMS::newData,RA_cOPC, &OPCN2::getData);
    connect(RA_cOPC, &OPCN2::newData ,this, &RacimoAire2::NewDataBME);

    connect(RA_cPMS, &PMS::InitMuestras, this, &RacimoAire2::initDataPMS);
    connect(RA_cOPC, &OPCN2::newData,this,&RacimoAire2::newDataOPC);

    RA_cOPC->setFanAndLaserOn();
    //RA_cOPC->ModeActive(TimeMuestreo/2);
    RA_cPMS->wakeUp();

    LogsThread = new LogsSystem(this);
    connect(LogsThread,&LogsSystem::SignalTemperatura,this, &RacimoAire2::SlotTemperatura);
    connect(LogsThread,&LogsSystem::SignalRAM,this, &RacimoAire2::SlotRAM);
    connect(LogsThread,&LogsSystem::SignalProcesos,this, &RacimoAire2::SlotProcesos);
    connect(LogsThread,&LogsSystem::SignalSOCKET,this, &RacimoAire2::SlotSOCKET);
    connect(LogsThread,&LogsSystem::SignalStatusWIFI,this, &RacimoAire2::SlotStatusWIFI);
    connect(LogsThread,&LogsSystem::SignalEspacioDisco,this, &RacimoAire2::SlotEspacioDisco);

    LogsThread->start(QThread::HighPriority);
    
    

}

RacimoAire2::~RacimoAire2()
{
    RA_cOPC->setFanAndLaserOff();
    RA_cPMS->sleep();
    qDebug()<< 1;delete RA_cBME280;
    qDebug()<< 2;delete RA_cGPS;

    qDebug()<< 3; delete _DataJson;
    qDebug()<< 4;delete RA_cData;
    qDebug()<< 5;delete RA_cOPC;
    qDebug()<< 6;delete RA_cPMS;
    qDebug()<< 6;delete txt_hum;
    qDebug()<< 7;delete txt_Presion;
    qDebug()<< 8;delete txt_temp;
    qDebug()<< 9;delete txt_longitud;
    qDebug()<< 10;delete txt_latitud;
    qDebug()<< 11;delete txt_Altitud;
    qDebug()<< 12;delete txt_Fix;
    qDebug()<< 13;delete txt_wifi;
    qDebug()<< 14;delete txt_PM25_P;
    qDebug()<< 15;delete txt_PM25_O;
    qDebug()<< 16;delete txt_PM10_P;
    qDebug()<< 17;delete txt_PM10_0;
    qDebug()<< 18;delete Serial;

    qDebug()<< 19;delete RA_cGPIO;



    delete ui;
}


void RacimoAire2::NewDataBME()
{

    float Humedad = RA_cBME280->readHumidity();
    float Temperatura =  RA_cBME280->readTemperature();
    float Presion = RA_cBME280->readPressure()/100.0F;
    float Altura = RA_cBME280->readAltitude(1013.25);
    QString comando= "clear";
    system(qPrintable(comando));
    qDebug() << "--------  Variable Meteorologicas ---------------\n \n";
    qDebug() << "Humedad = " << Humedad;
    qDebug() << "Temperatura = " << Temperatura;
    qDebug() << "Presion = " << Presion;
    qDebug() << "Altura = " <<Altura << "\n\n";

    qDebug() << "\n \n --------  Metadatos ---------------\n \n";

    qDebug() << "Temperatura Procesador = " << MetaData._Temperatura << "   RAM Usada = " << MetaData._RAM;
    qDebug() << "Numero de SOCKET abiertos = " << MetaData._SOCKET << "   Numero de procesos abiertos = " << MetaData._Procesos;
    qDebug() << "Estado WIFI = " << MetaData._StatusWIFI <<  "   RAM Usada = " << MetaData._EspacioDisco;

    qDebug() << "\n \n --------  MaterialParticulado --------------- \n\n";

    qDebug() << "PMS PM10 = "<< RA_cPMS->Data.PM_AE_UG_10_0 <<"  OPC PM10 = " << ((int)(RA_cOPC->Data.PM10*100))/100;
    qDebug() << "PMS PM10 = "<< RA_cPMS->Data.PM_AE_UG_2_5 <<"  OPC PM10 = " << ((int)(RA_cOPC->Data.PM2_5*100))/100;


    txt_temp->setText(QString::number(Temperatura).toStdString().c_str());
    txt_Presion->setText(QString::number(Presion).toStdString().c_str());
    txt_hum->setText(QString::number(Humedad).toStdString().c_str());
    _DataJson->SetDato(_DataJson->Humedad, (int) Humedad,false);
    _DataJson->SetDato(_DataJson->Presion, (int) Presion,false);
    _DataJson->SetDato(_DataJson->Temperatura, (int) Temperatura,false);
    _DataJson->WriteJson();

    /*
    RacimoHttp Comunicacion;
    QStringList _DataJsonString;
    if(MetaData._StatusWIFI){
        qDebug() <<_DataJson->readJson(&_DataJsonString);

        for(int i=0;i<_DataJsonString.length() ; i++)
        {
            std::string STR = QString(_DataJsonString.operator [](i)).toStdString();
            char String[1000];
            sprintf(String,"%s",STR.c_str());
            Comunicacion.POSTHttp(&String[0]);
            qDebug() << String;
        }
    }
    else
    {
        qDebug() << "NoWIFI";
    }*/

}



void RacimoAire2::newDataGPS()
{
    txt_longitud->setText(QString::number(RA_cGPS->longitudeDegrees).toStdString().c_str());
    txt_latitud->setText(QString::number(RA_cGPS->latitudeDegrees).toStdString().c_str());
    txt_Altitud->setText(QString::number(RA_cGPS->altitude).toStdString().c_str());
    txt_Fix->setText(QString::number(static_cast<int>(RA_cGPS->fixquality)).toStdString().c_str());
    _DataJson->SetDato(_DataJson->longitud, QString::number(RA_cGPS->longitudeDegrees));
    _DataJson->SetDato(_DataJson->latitud, QString::number(RA_cGPS->latitudeDegrees));
}

void RacimoAire2::newDataOPC(float PM1, float PM2_5, float PM10)
{
    _DataJson->SetDato(_DataJson->PM10, (static_cast<int>(PM10*100))/100.0,false);
    _DataJson->SetDato(_DataJson->PM2_5, (static_cast<int>(PM2_5*100))/100.0,false);
    txt_PM25_O->setText(QString::number(PM2_5).toStdString().c_str());
    txt_PM10_0->setText(QString::number(PM10).toStdString().c_str());
}

void RacimoAire2::newDataPMS(uint16_t PM1, uint16_t PM2_5, uint16_t PM10)
{
    _DataJson->SetDato(_DataJson->PM10PMS, (int)PM10,false);
    _DataJson->SetDato(_DataJson->PM2_5PMS, (int)PM2_5,false);
    txt_PM25_P->setText(QString::number(static_cast<int>(PM2_5)).toStdString().c_str());
    txt_PM10_P->setText(QString::number(static_cast<int>(PM10)).toStdString().c_str());
}

void RacimoAire2::initDataPMS()
{
    qDebug() << "Inicio de Muestreo";
}

void RacimoAire2::DataLogs()
{
    LogsThread->CheckESpacioDisco();
    LogsThread->CheckProcesos();
    LogsThread->CheckRAM();
    LogsThread->CheckSOCKET();
    LogsThread->CheckStatusWIFI();
    LogsThread->CheckTemperatura();
}

void RacimoAire2::SlotTemperatura(float temperatura)
{
    //qDebug() << "temperatura =" << temperatura;

    MetaData._Temperatura =temperatura;
}

void RacimoAire2::SlotRAM(float RAM)
{
    //qDebug() << "RAM =" << RAM;
   MetaData._RAM =RAM;
}

void RacimoAire2::SlotSOCKET(int SOCKET)
{
    //qDebug() << "SOCKET =" << SOCKET;
    MetaData._SOCKET =SOCKET;
}

void RacimoAire2::SlotProcesos(int Procesos)
{
    //qDebug() << "Procesos =" << Procesos;
    MetaData._Procesos = Procesos;
}

void RacimoAire2::SlotStatusWIFI(bool StatusWIFI)
{
    //qDebug() << "StatusWIFI =" << StatusWIFI;
    MetaData._StatusWIFI =StatusWIFI;
}

void RacimoAire2::SlotEspacioDisco(int EspacioDisco)
{
    //qDebug() << "EspacioDisco =" << EspacioDisco;
    MetaData._EspacioDisco =EspacioDisco;
}
