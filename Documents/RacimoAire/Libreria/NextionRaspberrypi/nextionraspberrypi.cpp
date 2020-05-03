#include "nextionraspberrypi.h"
#include <QDebug>
#include <QThread>

NextionRaspberrypi::NextionRaspberrypi(Crpigpio *_GPIO,unsigned baud,unsigned _GPIORX)
{
    GPIO_RX=_GPIORX;
    GPIO=_GPIO;
    begin(baud);
}

NextionRaspberrypi::~NextionRaspberrypi()
{
    //GPIO->CloseSerialgpio(GPIO_RX);
    GPIO->CloseSerial();
}

void NextionRaspberrypi::begin(unsigned baud)
{
    GPIO->OpenSerial(baud,0);
    GPIO->OpenSerialgpio(GPIO_RX,9600,8);
}

void NextionRaspberrypi::setTimeout(long time)
{
    timeout = time;
}

int NextionRaspberrypi::available()
{
    if(GPIO->AvailableSerial())qDebug() << "AJA ="<<GPIO->AvailableSerial();
    return GPIO->AvailableSerial();
}

uint8_t NextionRaspberrypi::read()
{
    return GPIO->ReadByteSerial();
}
int NextionRaspberrypi::read(char *buffer,unsigned size)
{
    return GPIO->ReadSerial(buffer,size);
}


int NextionRaspberrypi::readBytesnuf(char *buffer, size_t length)
{
    return GPIO->ReadSerialgpio(GPIO_RX,buffer, length);
}

size_t NextionRaspberrypi::readBytes(char *buffer, size_t length)
{
    size_t count =4;
    QThread::msleep(150);

    //while(count < length){
        //timeRead();

        //if(c<0)
         //   break;
        //*buffer++ = (char) c;
     //   count++;
    //}
    //int b = available();
    //qDebug() << "Tamano Espacio = " << b;
    //read(uffer,b);
    readBytesnuf(buffer,length);

    return (count);
}

int NextionRaspberrypi::timeRead()
{
    ulong TimeStart=millis();
    //int habilitado;
    do {
        /*habilitado =read();

        if(habilitado!=169)
        {
            qDebug() << "Habilitador = " << habilitado<< "   Time last = " << millis()-TimeStart;
            qDebug() << "Habilitador = " << available()<< "   Time last = " << millis()-TimeStart;
            qDebug() << "Habilitador = " << available()<< "   Time last = " << millis()-TimeStart << "\n\n\n";

            return habilitado;
        }*/
    }while(millis()-TimeStart<timeout);
    return -1;

}

void NextionRaspberrypi::write(char c)
{
    GPIO->WriteByteSerial(c);
}

void NextionRaspberrypi::write(uint8_t c)
{
    unsigned C=c;
    GPIO->WriteByteSerial(C);
}

void NextionRaspberrypi::write(uint16_t c)
{
    write(c>>8);
    write(c&0xff);

}

void NextionRaspberrypi::write(uint32_t c)
{
    write(c>>16);
    write(c&0xffff);
}

void NextionRaspberrypi::write(uint64_t c)
{
    write(c>>32);
    write(c&0xffffffff);
}

void NextionRaspberrypi::write(int8_t c)
{
    unsigned C=c;
    GPIO->WriteByteSerial(C);
}

void NextionRaspberrypi::write(int16_t c)
{
    write(c>>8);
    write(c&0xff);

}

void NextionRaspberrypi::write(int32_t c)
{
    write(c>>16);
    write(c&0xffff);
}

void NextionRaspberrypi::write(int64_t c)
{
    write(c>>32);
    write(c&0xffffffff);
}

void NextionRaspberrypi::print(QString String)
{
    char *charaja= new char[String.length()+1];
    strcpy(charaja,String.toStdString().c_str());

   for(int i=0; i<String.length() ; i++)
   {
       GPIO->WriteByteSerial(charaja[i]);
   }

}

void NextionRaspberrypi::print(const char *String)
{
    print(QString(String));
}

void NextionRaspberrypi::print(uint8_t val)
{
    write(val);
}

void NextionRaspberrypi::print(uint16_t val)
{
    write(val);
}

void NextionRaspberrypi::print(uint32_t val)
{
    write(val);
}

void NextionRaspberrypi::print(uint32_t *val)
{
    write(*val);
}

void NextionRaspberrypi::print(int8_t val)
{
    write(val);
}

void NextionRaspberrypi::print(int16_t val)
{
    write(val);
}

void NextionRaspberrypi::print(int32_t val)
{
    write(val);
}

void NextionRaspberrypi::print(int32_t *val)
{
    for(size_t i=0;i<sizeof(val);i+=4)write(val[i]);
}

void NextionRaspberrypi::println(QString String)
{
    String+="\r\n";
    print(String);
}

void NextionRaspberrypi::println(const char *String)
{
    QString String2= QString(String);
    String2+="\r\n";
    print(String2);
}

void NextionRaspberrypi::println(uint8_t val)
{
    QString String;
    String.number(static_cast<uint>(val));
    String += "\r\n";
    print(String);
}

void NextionRaspberrypi::println(uint16_t val)
{
    QString String;
    String.number(static_cast<uint>(val));
    String += "\r\n";
    print(String);
}

void NextionRaspberrypi::println(uint32_t val)
{
    QString String;
    String.number(static_cast<ulong>(val));
    String += "\r\n";
    print(String);
}


void NextionRaspberrypi::println(uint32_t *val)
{
    QString String;
    for(size_t i=0;i<sizeof(val);i+=4)
    {
        String += String.number(static_cast<ulong>(val[i]));
    }
    String += "\r\n";
    print(String);
}

void NextionRaspberrypi::println(int8_t val)
{
    QString String;
    String.number(static_cast<int>(val));
    String += "\r\n";
    print(String);
}

void NextionRaspberrypi::println(int16_t val)
{
    QString String;
    String.number(static_cast<int>(val));
    String += "\r\n";
    print(String);
}

void NextionRaspberrypi::println(int32_t val)
{
    QString String;
    String.number(static_cast<long>(val));
    String += "\r\n";
    print(String);
}



void NextionRaspberrypi::println(int32_t *val)
{
    QString String;
    for(size_t i=0;i<sizeof(val);i+=4)
    {
        String += String.number(static_cast<long>(val[i]));
    }
    String += "\r\n";
    print(String);
}

ulong NextionRaspberrypi::millis()
{
    QTime _millis= QTime::currentTime();
    ulong Time = (_millis.hour()*60)+(_millis.minute()*60)+(_millis.second()*1000)+_millis.msec();
    return Time;
}


