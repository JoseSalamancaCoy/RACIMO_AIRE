#include "appracimoaire.h"
#include "ui_appracimoaire.h"

appRacimoAire::appRacimoAire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::appRacimoAire)
{
    ui->setupUi(this);
    TimeMuestreo =1000;
    RA_cGPIO = new Crpigpio;
    RA_cGPIO2 = new Crpigpio(false);
    RA_cGPIO3 = new Crpigpio(false);

    RA_cPMS = new PMS(RA_cGPIO,GPIOPMSSet, GPIOPMSReSet, GPIOPMSRX,TimeMuestreo);
    RA_cGPS = new GPS(RA_cGPIO, GPIOGPSRX, GPIOGPSPPS);
    RA_cOPC = new OPCN2(RA_cGPIO,0,0);
    RA_cBME280 = new Adafruit_BME280(RA_cGPIO,0x77);

    //RA_cGADC = new ADS1115(RA_cGPIO2);
    //RA_cCorriente = new Adafruit_INA219(RA_cGPIO3);

    RA_cData = new DataParticulado(RA_cOPC,RA_cPMS,TimeMuestreo,60000);
    RA_cData->SetNumMuestras(2);
    _DataJson =new DataJson("uis-11","UIS-11","-73.12194","7.140129","/home/pi/RACIMOAIRE");


    //Serial =new NextionRaspberrypi(RA_cGPIO,9600,15);
    //nexInit(Serial);
    //txt_temp = new NexText(Serial,0,9,"t7");
    //txt_Presion = new NexText(Serial,0,10,"t8");
    //txt_hum = new NexText(Serial,0,13,"t11");
    //txt_longitud = new NexText(Serial,0,15,"t13");
    //txt_latitud = new NexText(Serial,0,18,"t16");
    //txt_Altitud = new NexText(Serial,0,19,"t17");
    //txt_Fix = new NexText(Serial,0,17,"t15");
    //txt_wifi = new NexText(Serial,0,20,"t18");
    //txt_PM25_P = new NexText(Serial,0,25,"t23");
    //txt_PM25_O = new NexText(Serial,0,29,"t27");
    //txt_PM10_P = new NexText(Serial,0,26,"t24");
    //txt_PM10_0 = new NexText(Serial,0,30,"t28");


    TimeMuestraPromedioBME = new QTimer;
    TimeMuestraPromedioBME->setInterval(10000);
    TimeMuestraPromedioBME->start();
    connect(TimeMuestraPromedioBME,&QTimer::timeout,this, &appRacimoAire::NewDataBME);
    connect(RA_cGPS,&GPS::newData,this, &appRacimoAire::newDataGPS);
    connect(RA_cData,&DataParticulado::DataOk,this, &appRacimoAire::DataOk);

}

appRacimoAire::~appRacimoAire()
{
    RA_cOPC->setFanAndLaserOff();
    RA_cPMS->sleep();
    //delete RA_cGADC;
    //delete RA_cCorriente;
    qDebug()<< 1;delete RA_cBME280;
    qDebug()<< 2; delete _DataJson;
    qDebug()<< 3;delete RA_cData;
    qDebug()<< 4;delete RA_cOPC;
    qDebug()<< 5;delete RA_cPMS;
    /*qDebug()<< 6;delete //txt_hum;
    qDebug()<< 7;delete //txt_Presion;
    qDebug()<< 8;delete //txt_temp;
    qDebug()<< 9;delete //txt_longitud;
    qDebug()<< 10;delete //txt_latitud;
    qDebug()<< 11;delete //txt_Altitud;
    qDebug()<< 12;delete //txt_Fix;
    qDebug()<< 13;delete //txt_wifi;
    qDebug()<< 14;delete //txt_PM25_P;
    qDebug()<< 15;delete //txt_PM25_O;
    qDebug()<< 16;delete //txt_PM10_P;
    qDebug()<< 17;delete //txt_PM10_0;*/
    //qDebug()<< 18;delete Serial;


    qDebug()<< 19;delete RA_cGPIO;

    delete ui;
}

void appRacimoAire::NewDataBME()
{
    float Humedad = RA_cBME280->readHumidity();
    float Temperatura =  RA_cBME280->readTemperature();
    float Presion = RA_cBME280->readPressure()/100.0F;
    float Altura = RA_cBME280->readAltitude(1013.25);


    qDebug() << Humedad;
    qDebug() << Temperatura;
    qDebug() << Presion;
    qDebug() <<Altura << "\n\n\n\n";

    //txt_temp->setText(QString::number(Temperatura).toStdString().c_str());
    //txt_Presion->setText(QString::number(Presion).toStdString().c_str());
    //txt_hum->setText(QString::number(Humedad).toStdString().c_str());
    //txt_Altitud->setText(QString::number(Altura).toStdString().c_str());



}



void appRacimoAire::newDataGPS(float latitude, float longitude, float latitudeDegrees, float longitudeDegrees, int32_t latitude_fixe, int32_t longitude_fixed)
{
    //qDebug() << "Fix = " << RA_cGPS->fixquality;

    //txt_longitud->setText(QString::number(longitudeDegrees).toStdString().c_str());
    //txt_latitud->setText(QString::number(latitudeDegrees).toStdString().c_str());
    //txt_Altitud->setText(QString::number(RA_cGPS->altitude).toStdString().c_str());
    //txt_Fix->setText(QString::number(static_cast<int>(RA_cGPS->fixquality)).toStdString().c_str());
    //qDebug() << "latitudeDegrees = "<<latitudeDegrees<< "longitudeDegrees = "<<longitudeDegrees;
    //qDebug() <<QString("%1-%2-%3T%4:%5:%6.%7").arg(RA_cGPS->year).arg(RA_cGPS->month).arg(RA_cGPS->day).arg(RA_cGPS->hour).arg(RA_cGPS->minute).arg(RA_cGPS->seconds).arg(RA_cGPS->milliseconds);
}



void  appRacimoAire::DataOk(DataParticulado::DATARACIMO *_Data, DataParticulado::Struct_MOPC *_MOPC, DataParticulado::Struct_MPMS *_MPMS)
{
    QString comando= "clear";
    system(qPrintable(comando));

    //AdminLogsSystem *LOGS= new AdminLogsSystem(LogsSystem::_ObtenerRAM);
    //delete LOGS;
    float Humedad = RA_cBME280->readHumidity();
    float Temperatura =  RA_cBME280->readTemperature();
    float Presion = RA_cBME280->readPressure()/100.0F;
    float Altura = RA_cBME280->readAltitude(1013.25);


    /*qDebug() << Humedad;
    qDebug() << Temperatura;
    qDebug() << Presion;
    qDebug() <<Altura << "\n\n\n\n";

    j0->setValue(Temperatura*2);
    //txt_temp->setText(QString::number(Temperatura).toStdString().c_str());
    //txt_hum->setText(QString::number(Humedad).toStdString().c_str());
    */
/*  qDebug()<<"RAM = " <<LOGS->initHilo(LogsSystem::_ObtenerRAM);
    qDebug()<<"Espacio Disco = " <<LOGS->initHilo(LogsSystem::_ObtenerEspacioDisco);
    qDebug()<<"Procesos = " <<LOGS->initHilo(LogsSystem::_ObtenerProcesos);
    qDebug()<<"Temperatura Procesador =" <<LOGS->initHilo(LogsSystem::_ObtenerTemperatura);
    qDebug()<<"Socket = "<<LOGS->initHilo(LogsSystem::_ObtenerSOCKET);
    qDebug()<<"StatusWIFI = " <<LOGS->initHilo(LogsSystem::_ObtenerStatusWIFI);
*/


    _DataJson->SetDato(_DataJson->Humedad, (int) Humedad,false);
    _DataJson->SetDato(_DataJson->Presion, (int) Presion,false);
    _DataJson->SetDato(_DataJson->Temperatura, (int) Temperatura,false);
    _DataJson->SetDato(_DataJson->PM10, (int)_Data->OPC_PM_10,false);
    _DataJson->SetDato(_DataJson->PM2_5, (int)_Data->OPC_PM_2_5,false);
    _DataJson->SetDato(_DataJson->PM10PMS, (int)_Data->PMS_PM_10,false);
    _DataJson->SetDato(_DataJson->PM2_5PMS, (int)_Data->PMS_PM_2_5,false);
    _DataJson->WriteJson();

    //txt_PM25_P->setText(QString::number(static_cast<int>(_Data->PMS_PM_2_5)).toStdString().c_str());
    //txt_PM25_O->setText(QString::number(static_cast<int>(_Data->OPC_PM_2_5)).toStdString().c_str());
    //txt_PM10_P->setText(QString::number(static_cast<int>(_Data->PMS_PM_10)).toStdString().c_str());
    //txt_PM10_0->setText(QString::number(static_cast<int>(_Data->OPC_PM_10)).toStdString().c_str());
    RacimoHttp Comunicacion;
    QStringList _DataJsonString;
    qDebug() <<_DataJson->readJson(&_DataJsonString);

   /* for(int i=0;i<_DataJsonString.length() ; i++)
    {
        std::string STR = QString(_DataJsonString.operator [](i)).toStdString();
        char String[1000];
        sprintf(String,"%s",STR.c_str());
        Comunicacion.POSTHttp(&String[0]);
        qDebug() << String;
    }
*/


   // qDebug() << str;

}
