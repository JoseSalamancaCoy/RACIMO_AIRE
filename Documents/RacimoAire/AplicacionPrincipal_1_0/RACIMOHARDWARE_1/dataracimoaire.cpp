#include "dataracimoaire.h"
#include <QDebug>
DataRacimoAire::DataRacimoAire(OPCN2 *_RA_cOPC,PMS *_RA_cPMS,QWidget *parent)
{
    RA_cOPC=_RA_cOPC;
    RA_cPMS=_RA_cPMS;
    TimeMuestreo = 10000;
    TimeMuestraPromedio = new QTimer;
    TimeMuestraPromedio->setInterval(420000);
    QObject::connect(TimeMuestraPromedio, SIGNAL(timeout()), this, SLOT(InitMuestraDataPromedio()));
    QObject::connect(RA_cPMS, SIGNAL(newData(uint16_t,uint16_t,uint16_t)),this, SLOT(newDataPMS(uint16_t,uint16_t,uint16_t)));
    QObject::connect(RA_cPMS, SIGNAL(InitMuestras()), this, SLOT(initDataPMS()));
    QObject::connect(RA_cOPC, SIGNAL(newData(float,float,float)),this,SLOT(newDataOPC(float,float,float)));
    RA_cOPC->initialize();
    RA_cOPC->setFanAndLaserOff();
    RA_cPMS->sleep();
    TimeMuestraPromedio->start();
    ResetData();


}

void DataRacimoAire::ResetData()//Establece en 0 las variables
{
    Cont_Muestras_PMS=0;
    Cont_Muestras_OPC=0;
    _MPromPMS_PM10=0;
    _MPromPMS_PM2_5=0;
    _MPromPMS_PM1=0;

    _MPromOPC_PM10=0;
    _MPromOPC_PM2_5=0;
    _MPromOPC_PM1=0;

    _Data.LatitudDegrees=0;
    _Data.LongitudDegrees=0;

    _Data.OPC_PM_1 =0;
    _Data.OPC_PM_2_5=0;
    _Data.OPC_PM_10=0;
    _Data.PMS_PM_10=0;
    _Data.PMS_PM_2_5=0;
    _Data.PMS_PM_1=0;


    PMS_Ok = false; //Finalizacion de toma de datos de PMS
    OPC_Ok = false; //Finalizacion de toma de datos de OPC
    for(int i = 0; i < Num_Muestras; i++ ) //Inicion en 0 de bufers de muestras
    {
        _MPMS.PM10[i]=0;
        _MPMS.PM2_5[i]=0;
        _MPMS.PM10[i]=0;

        _MOPC.PM10[i]=0;
        _MOPC.PM2_5[i]=0;
        _MOPC.PM10[i]=0;
    }

}

DataRacimoAire::~DataRacimoAire()
{
    delete TimeMuestraPromedio;
}

void DataRacimoAire::Promedio(QString Variable, uint16_t Valor) //Promedio para PMS
{
    if(Variable == "PM10"){
        _MPromPMS_PM10 = (_MPromPMS_PM10 + Valor)/Num_Muestras;
        _MPMS.PM10[Cont_Muestras_PMS] = Valor;
    }
    else if(Variable == "PM2_5"){
        _MPromPMS_PM2_5 = (_MPromPMS_PM2_5 + Valor)/Num_Muestras;
        _MPMS.PM2_5[Cont_Muestras_PMS] = Valor;

    }
    else if(Variable == "PM1"){
        _MPromPMS_PM1 = (_MPromPMS_PM1 + Valor)/Num_Muestras;
        _MPMS.PM1[Cont_Muestras_PMS] = Valor;
    }
}

void DataRacimoAire::Promedio(QString Variable, float Valor) //Promedio para OPC
{
    if(Cont_Muestras_OPC >= Num_Muestras)
    {
        OPC_Ok=true;
    }
    if(Variable == "PM10"){
        _MPromOPC_PM10 = (_MPromOPC_PM10 + Valor) / Num_Muestras;
        _MOPC.PM10[Cont_Muestras_OPC] = Valor;
    }
    else if(Variable == "PM2_5"){
        _MPromOPC_PM2_5 = (_MPromOPC_PM2_5 + Valor) / Num_Muestras;
        _MOPC.PM2_5[Cont_Muestras_OPC] = Valor;

    }
    else if(Variable == "PM1"){
        _MPromOPC_PM1 = (_MPromOPC_PM1 + Valor) / Num_Muestras;
        _MOPC.PM1[Cont_Muestras_OPC] = Valor;
    }
}

void DataRacimoAire::AddMuestraPMS()
{
    Cont_Muestras_PMS++;
    if(Cont_Muestras_PMS >= Num_Muestras)
    {
        PMS_Ok=true;
        checkStatus();
    }
}

void DataRacimoAire::AddMuestraOPC()
{
    Cont_Muestras_OPC++;
    if(Cont_Muestras_OPC >= Num_Muestras)
    {
        PMS_Ok=true;
        checkStatus();
    }
}

//Emite una senal cuando las muestras de los sensores es completada
DataRacimoAire::StatusMuestras DataRacimoAire::checkStatus() //Retorna Estado de Muestras
{
    if(OPC_Ok && PMS_Ok)
    {
        _Data.PMS_PM_10 = _MPromPMS_PM10;
        _Data.PMS_PM_2_5 = _MPromPMS_PM2_5;
        _Data.PMS_PM_1 = _MPromPMS_PM1;

        _Data.OPC_PM_10 = _MPromOPC_PM10;
        _Data.OPC_PM_2_5 = _MPromOPC_PM2_5;
        _Data.OPC_PM_1 = _MPromOPC_PM1;
        emit DataOk(&_Data, &_MOPC, &_MPMS);
        PMS_Ok = false;
        OPC_Ok = false;
        Cont_Muestras_OPC=0;
        Cont_Muestras_PMS=0;
        return DataRacimoAire::StatusMuestras::MuestrasCompletas;
    }
    else if(OPC_Ok && !PMS_Ok) return  DataRacimoAire::StatusMuestras::EsperandoPMS;
    else if(!OPC_Ok && PMS_Ok) return  DataRacimoAire::StatusMuestras::EsperandoOPC;
    else if(!OPC_Ok && !PMS_Ok) return  DataRacimoAire::StatusMuestras::EsperandoPMS_OPC;
}


void DataRacimoAire::InitMuestraDataPromedio()
{
    RA_cPMS->wakeUp();
    bool ok=true;
    RA_cOPC->setFanAndLaserOn(&ok);
    RA_cOPC->ModeActive(TimeMuestreo);
    TimeMuestraPromedio->stop();

}


void DataRacimoAire::newDataOPC(float PM1, float PM2_5, float PM10)
{
    Promedio("PM10", PM10);   Promedio("PM2_5", PM2_5);   Promedio("PM1", PM1); AddMuestraOPC();
}


void DataRacimoAire::newDataPMS(uint16_t PM1, uint16_t PM2_5, uint16_t PM10)
{
    Promedio("PM10",PM10);  Promedio("PM2_5",PM2_5);  Promedio("PM1",PM1); AddMuestraPMS();

}

void DataRacimoAire::initDataPMS()
{

    qDebug() <<"Init";
}
