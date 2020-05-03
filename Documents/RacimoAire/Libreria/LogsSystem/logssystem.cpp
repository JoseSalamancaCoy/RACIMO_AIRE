#include "logssystem.h"



LogsSystem::LogsSystem(QObject *parent):QThread(parent)
{
    Stop=false;
}

void LogsSystem::Restart()
{
    run();
}

void LogsSystem::stop()
{
    Stop=true;
}

void LogsSystem::CheckTemperatura()
{
    Temperatura = true;
}

void LogsSystem::CheckRAM()
{
    RAM= true;

}

void LogsSystem::CheckSOCKET()
{
    SOCKET= true;

}

void LogsSystem::CheckProcesos()
{
    Procesos= true;

}

void LogsSystem::CheckStatusWIFI()
{
    StatusWIFI= true;
}

void LogsSystem::CheckESpacioDisco()
{
    EspacioDisco= true;
}


void LogsSystem::doWork(int accion) {
    QString result;
    result = "DoWork";
    switch (accion) {
    case _ObtenerTemperatura:
    {
        float Temperatura;Temperatura = ObtenerTemperatura();
        if(Temperatura==0.0) return;
        emit SignalTemperatura(Temperatura);
        break;
    }
    case _ObtenerRAM:
    {
        float RAM;RAM = ObtenerRAM();
        if(RAM==0) return;
        emit SignalRAM(RAM);
        break;
    }
    case _ObtenerSOCKET:
    {
        int Sockets;Sockets = ObtenerSOCKET();
        if(Sockets == 15555) return;
        emit SignalSOCKET(Sockets);
        break;
    }
    case _ObtenerProcesos:
    {
        int Procesos;Procesos = ObtenerProcesos();
        if(Procesos == 0) return;
        emit SignalProcesos(Procesos);
        break;
    }
    case _ObtenerStatusWIFI:
    {
        bool StatusWIFI;StatusWIFI = ObtenerStatusWIFI();
        emit SignalStatusWIFI(StatusWIFI);
        break;
    }
    case _ObtenerEspacioDisco:
    {
        int EspacioDisco;EspacioDisco = ObtenerEspacioDisco();
        if(EspacioDisco == 0) return;
        emit SignalEspacioDisco(EspacioDisco);
        break;
    }
    default:
        break;
    }
    emit resultReady(result);
}

void LogsSystem::run()
{
    Stop=false;

    while (!Stop) {

        if(Temperatura){Temperatura = false; doWork(_ObtenerTemperatura);}
        if(RAM){RAM = false; doWork(_ObtenerRAM);}
        if(SOCKET){SOCKET = false; doWork(_ObtenerSOCKET);}
        if(Procesos){Procesos = false; doWork(_ObtenerProcesos);}
        if(StatusWIFI){StatusWIFI = false; doWork(_ObtenerStatusWIFI);}
        if(EspacioDisco){EspacioDisco = false; doWork(_ObtenerEspacioDisco);}
        msleep(100);
    }

}

float LogsSystem::ObtenerTemperatura()
{
    QFile file("/sys/class/thermal/thermal_zone0/temp");
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qDebug() << "falla al leer temperatura";
       return 0.0; //Error
    }
    else
    {
        QByteArray Temp= file.readLine();
        Temp.chop(1);
        file.close();
        float Temperatura =Temp.toFloat()/1000;
        return Temperatura;

    }
}

float LogsSystem::ObtenerRAM()
{
    system("free | grep Mem | awk '{print $2 \";\" $3}' >/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/RAM");
    QFile file("/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/RAM");
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qDebug() << "falla al leer temperatura";
       return 0; //Error
    }
    else
    {
        QStringList line1 =QString(file.readAll()).split(";");
        file.close();
        QString RamUSED = line1.operator [](1);
        QString RamTotal = line1.operator [](0);
        return ((100*(RamUSED.toFloat() / RamTotal.toFloat())));
    }
}

int LogsSystem::ObtenerSOCKET()
{
    system("sudo lsof -iTCP | wc -l >/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/Sokeds");
    QFile file("/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/Sokeds");
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qDebug() << "falla al obtener numero de socketsTCP abiertos";
       return 15555; //Error
    }
    else
    {
        QByteArray Socket = file.readAll();
        file.close();
        Socket.chop(1);
        int IntSockets = Socket.toInt() - 1 ;
        return IntSockets;

    }
}

int LogsSystem::ObtenerProcesos()
{
    system("sudo ps ax | wc -l >/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/Procesos");
    QFile file("/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/Procesos");
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qDebug() << "falla al obtener numero de Procesos";
       return 0; //Error
    }
    else
    {
        QByteArray Procesos = file.readAll();
        file.close();
        Procesos.chop(1);
        int IntProcesos = Procesos.toInt() - 2 ;
        return IntProcesos;
    }
}

bool LogsSystem::ObtenerStatusWIFI()
{
    system("sudo ping -c1 google.com | wc -l >/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/StatusWifi");
    system("sudo iwlist wlan0 scan | grep ESSID >/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/ESSID_WIFI");
    QFile fileESSID("/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/StatusWifi");
    if(!fileESSID.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qDebug() << "falla al obtener status WIFI";
       return false;
    }
    else
    {
        QByteArray Procesos = fileESSID.readAll();
        fileESSID.close();
        Procesos.chop(1);
        if( Procesos.toInt() <= 0) return false;
    }

    QFile file("/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/StatusWifi");
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qDebug() << "falla al obtener status WIFI";
       return false;
    }
    else
    {
        QByteArray Procesos = file.readAll();
        file.close();
        Procesos.chop(1);
        if( Procesos.toInt() > 0)return true;
        else return false;
    }
}

int LogsSystem::ObtenerEspacioDisco()
{
    system("df -h | grep /dev/root | awk '{print $5}' >/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/freeDisk");

    QFile file("/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/freeDisk");
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
       qDebug() << "falla al leer temperatura";
       return 0;
    }
    else
    {
        QString line1 =QString(file.readLine());
        file.close();
        line1.chop(2);
        return line1.toInt();

    }
}

