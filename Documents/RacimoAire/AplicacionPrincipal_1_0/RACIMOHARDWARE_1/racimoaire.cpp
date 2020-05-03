#include "racimoaire.h"
#include "ui_racimoaire.h"

#define GPIOPMSSet 13
#define GPIOPMSReSet 5
#define GPIOPMSRX 6
#define GPIOGPSRX 23
#define GPIOGPSPPS 24

RACIMOAIRE::RACIMOAIRE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RACIMOAIRE)
{
    ui->setupUi(this);
    TimeMuestreo = 10000;
    TimeMuestraPromedio = new QTimer;
    TimeMuestraPromedio->setInterval(420000);
    RA_cGPIO = new Crpigpio;
    RA_cPMS = new PMS(RA_cGPIO,GPIOPMSSet, GPIOPMSReSet, GPIOPMSRX,TimeMuestreo);
    RA_cGPS = new GPS(RA_cGPIO, GPIOGPSRX, GPIOGPSPPS);
    RA_cOPC = new OPCN2(RA_cGPIO);
    RA_cData = new DataRacimoAire(RA_cOPC,RA_cPMS);

    connect(RA_cGPS, SIGNAL(newData(float,float,float,float,int32_t,int32_t)),this, SLOT(newDataGPS(float,float,float,float,int32_t,int32_t)));
    connect(RA_cData, SIGNAL(DataOk(DataRacimoAire::DATARACIMO*,DataRacimoAire::Struct_MOPC*,DataRacimoAire::Struct_MPMS*)),
                this, SLOT(DataOk(DataRacimoAire::DATARACIMO*,DataRacimoAire::Struct_MOPC*,DataRacimoAire::Struct_MPMS*)));
    DateTime = QDateTime::currentDateTime();
    DateTimeStr =DateTime.date().toString(Qt::ISODate) +  "_P_" +DateTime.time().toString(Qt::ISODate);
    DateTimeStr = DateTimeStr.replace("-","_");
    DateTimeStr = DateTimeStr.replace(":","_");

    addrarchivo = "/home/pi/Documents/RacimoAire/Data/Data_" + DateTimeStr + ".csv";
    TimeMuestraPromedio->destroyed();
    TimeMuestraPromedio->start();
/*******************************************************************************/
    QFile file(addrarchivo);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() <<"Falla al abrir el archivo1";
        return;
    }
    QString str;
    str = "PMS: PM1; PMS: PM2.5; PMS: PM10;-; OPC: PM1; OPC: PM2.5; OPC: PM10;-;Tiempo \n";
    QTextStream strem(&file);
    strem << str;
    file.close();

/*******************************************************************************/
    QFile file2(addrarchivo.replace("P", "T"));
    if(!file2.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() <<"Falla al abrir el archivo2";
        return;
    }
    str = "PMS: PM1; PMS: PM2.5; PMS: PM10;-; OPC: PM1; OPC: PM2.5; OPC: PM10;-;Tiempo \n";
    QTextStream strem2(&file2);
    strem2 << str;
    file2.close();
}

RACIMOAIRE::~RACIMOAIRE()
{
    RA_cOPC->setFanAndLaserOff();
    RA_cPMS->sleep();
    delete RA_cOPC;
    delete RA_cPMS;
    delete RA_cGPIO,
            delete ui;
}



void RACIMOAIRE::newDataGPS(float latitude, float longitude, float latitudeDegrees, float longitudeDegrees, int32_t latitude_fixe, int32_t longitude_fixed)
{

}



void  RACIMOAIRE::DataOk(DataRacimoAire::DATARACIMO *_Data, DataRacimoAire::Struct_MOPC *_MOPC, DataRacimoAire::Struct_MPMS *_MPMS)
{
    QString comando= "clear";
    system(qPrintable(comando));
    qDebug() <<" Variable    |       PMS           |           OPC";
    qDebug() <<"PM10 =              " << _Data->PMS_PM_10 << "                   " << _Data->OPC_PM_10;
    qDebug() <<"PM2_5 =             " << _Data->PMS_PM_2_5 << "                   " << _Data->OPC_PM_2_5;
    qDebug() <<"PM1 =                " << _Data->PMS_PM_1 << "                   " << _Data->OPC_PM_1;
    qDebug() <<"SAVE DATA....";



    QFile file(addrarchivo.replace("T","P"));
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() <<"Falla al abrir el archivo";
        return;
    }
    Time = QTime::currentTime();
    QString str;
    str = QString::number(_Data->PMS_PM_1) + ";";
    str += QString::number(_Data->PMS_PM_2_5) + ";";
    str += QString::number(_Data->PMS_PM_10) + ";-;";
    str += QString::number(_Data->OPC_PM_1) + ";";
    str += QString::number(_Data->OPC_PM_2_5) + ";";
    str += QString::number(_Data->OPC_PM_10) +   ";-;";
    str += Time.toString(Qt::ISODate) + "\n";
    qDebug() << "Fecha = " << DateTime.currentDateTime();
    QTextStream strem(&file);
    strem << str;
    file.close();

    QFile file2(addrarchivo.replace("P", "T"));
    if(!file2.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() <<"Falla al abrir el archivo";
        return;
    }
    str = " ";
    for(int i = 0; i < RA_cData->Num_Muestras; i++)
    {
        str += QString::number(_MPMS->PM1[i]) + ";";
        str += QString::number(_MPMS->PM2_5[i]) + ";";
        str += QString::number(_MPMS->PM10[i]) +  ";-;";
        str += QString::number(_MOPC->PM1[i]) + ";";
        str += QString::number(_MOPC->PM2_5[i]) + ";";
        str += QString::number(_MOPC->PM10[i]) + ";-;";
        str += Time.addSecs(-(RA_cData->Num_Muestras*TimeMuestreo/1000)+i).toString(Qt::ISODate) + "\n";

    }
    QTextStream strem2(&file2);
    strem2 << str;
    file2.close();

    RA_cOPC->setFanAndLaserOff();
    RA_cOPC->ModePassive();
    RA_cPMS->sleep();
    TimeMuestraPromedio->start();
}
