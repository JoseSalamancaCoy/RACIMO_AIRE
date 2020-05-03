 #include "dataparticulado.h"

#include <QDebug>
DataParticulado::DataParticulado(OPCN2 *_RA_cOPC,PMS *_RA_cPMS,uint32_t tiempoMuestreo,uint32_t TiempoMuestraPromedio,QObject *parent) : QObject(parent)
{
    RA_cOPC=_RA_cOPC;
    RA_cPMS=_RA_cPMS;
    TimeMuestreo = tiempoMuestreo;
    tiempoSLeep =TiempoMuestraPromedio-60000 -(TimeMuestreo*Num_Muestras) ;
    TimeMuestraPromedio = new QTimer;
    Activo(tiempoSLeep);
    _errorPMS = new QTimer;
    _errorPMS->setInterval(TimeMuestreo/2);

    QObject::connect(_errorPMS, SIGNAL(timeout()), this, SLOT(CheckfirstdataPMS()));
    QObject::connect(TimeMuestraPromedio, SIGNAL(timeout()), this, SLOT(InitMuestraDataPromedio()));
    QObject::connect(RA_cPMS, SIGNAL(newData(uint16_t,uint16_t,uint16_t)),this, SLOT(newDataPMS(uint16_t,uint16_t,uint16_t)));
    QObject::connect(RA_cPMS, SIGNAL(InitMuestras()), this, SLOT(initDataPMS()));
    QObject::connect(RA_cOPC, SIGNAL(newData(float,float,float)),this,SLOT(newDataOPC(float,float,float)));
    RA_cOPC->setFanAndLaserOff();
    RA_cPMS->sleep();
    ResetData();


   // Num_Muestras=12;
}

void DataParticulado::ResetData()//Establece en 0 las variables
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

void DataParticulado::SetNumMuestras(size_t _Num_Muestras)
{
    // Num_Muestras = _Num_Muestras;
}

void DataParticulado::Muestra()
{
    InitMuestraDataPromedio();
}

void DataParticulado::Activo(uint32_t TimeSleep)
{
    TimeMuestraPromedio->setInterval(TimeSleep);
    TimeMuestraPromedio->start();
    _Pasivo=false;
}

void DataParticulado::Pasivo()
{
    _Pasivo=true;
    TimeMuestraPromedio->stop();
}

DataParticulado::~DataParticulado()
{
    delete TimeMuestraPromedio;
}

void DataParticulado::Promedio(QString Variable, uint16_t Valor) //Promedio para PMS
{
    if(Cont_Muestras_PMS <=Num_Muestras)
    {
        if(Variable == "PM10"){
            _MPromPMS_PM10 += ((float)Valor/Num_Muestras);
            _MPMS.PM10[Cont_Muestras_PMS] = Valor;
        }
        else if(Variable == "PM2_5"){
            _MPromPMS_PM2_5 += ((float)Valor/Num_Muestras);
            _MPMS.PM2_5[Cont_Muestras_PMS] = Valor;

        }
        else if(Variable == "PM1"){
            _MPromPMS_PM1 += ((float)Valor/Num_Muestras);
            _MPMS.PM1[Cont_Muestras_PMS] = Valor;
        }
    }
}

void DataParticulado::Promedio(QString Variable, float Valor) //Promedio para OPC
{
    if(Cont_Muestras_OPC >= Num_Muestras+1)
    {
        OPC_Ok=true;
    }
    if(Cont_Muestras_OPC!=0 && Cont_Muestras_PMS <=Num_Muestras+1)
    {
        if(Variable == "PM10"){
            _MPromOPC_PM10 += (Valor) / Num_Muestras;
            _MOPC.PM10[Cont_Muestras_OPC-1] = Valor;
        }
        else if(Variable == "PM2_5"){
            _MPromOPC_PM2_5 += (Valor) / Num_Muestras;
            _MOPC.PM2_5[Cont_Muestras_OPC-1] = Valor;

        }
        else if(Variable == "PM1"){
            _MPromOPC_PM1 += (Valor) / Num_Muestras;
            _MOPC.PM1[Cont_Muestras_OPC-1] = Valor;
        }
    }
}

void DataParticulado::AddMuestraPMS()
{
    Cont_Muestras_PMS++;

    if(Cont_Muestras_PMS >= Num_Muestras)
    {
        PMS_Ok=true;
        checkStatus();
    }
}

void DataParticulado::AddMuestraOPC()
{
    Cont_Muestras_OPC++;
    if(Cont_Muestras_OPC >= Num_Muestras)
    {
        OPC_Ok=true;
        checkStatus();
    }
}

//Emite una senal cuando las muestras de los sensores es completada
DataParticulado::StatusMuestras DataParticulado::checkStatus() //Retorna Estado de Muestras
{
    if(OPC_Ok && PMS_Ok)
    {
        _Data.PMS_PM_10 = _MPromPMS_PM10;
        _Data.PMS_PM_2_5 = _MPromPMS_PM2_5;
        _Data.PMS_PM_1 = _MPromPMS_PM1;

        _Data.OPC_PM_10 = _MPromOPC_PM10;
        _Data.OPC_PM_2_5 = _MPromOPC_PM2_5;
        _Data.OPC_PM_1 = _MPromOPC_PM1;
        if(Cont_Muestras_OPC>0) emit DataOkOPC(_MPromOPC_PM1,_MPromOPC_PM2_5,_MPromOPC_PM10);
        if(Cont_Muestras_PMS>0) emit DataOkPMS(_MPromPMS_PM1,_MPromPMS_PM2_5,_MPromPMS_PM10);
        emit DataOk();
        PMS_Ok = false;
        OPC_Ok = false;
        Cont_Muestras_PMS=0;
        _MPromPMS_PM10=0;
        _MPromPMS_PM2_5=0;
        _MPromPMS_PM1=0;

        RA_cPMS->sleep();
        RA_cOPC->setFanAndLaserOff();
        RA_cOPC->ModePassive();
        Cont_Muestras_OPC=0;
        _MPromOPC_PM10=0;
        _MPromOPC_PM2_5=0;
        _MPromOPC_PM1=0;
        if(!_Pasivo) TimeMuestraPromedio->start();

        return DataParticulado::StatusMuestras::MuestrasCompletas;
    }
    else if(OPC_Ok && !PMS_Ok && Cont_Muestras_OPC>0)
    {
        emit DataOkOPC(_MPromOPC_PM1,_MPromOPC_PM2_5,_MPromOPC_PM10);
        RA_cOPC->setFanAndLaserOff();
        RA_cOPC->ModePassive();
        Cont_Muestras_OPC=0;
        _MPromOPC_PM10=0;
        _MPromOPC_PM2_5=0;
        _MPromOPC_PM1=0;
        if(!_Pasivo)TimeMuestraPromedio->start();

        return  DataParticulado::StatusMuestras::EsperandoPMS;
    }
    else if(!OPC_Ok && PMS_Ok&& Cont_Muestras_PMS>0)
    {
        emit DataOkPMS(_MPromPMS_PM1,_MPromPMS_PM2_5,_MPromPMS_PM10);
        RA_cPMS->sleep();
         Cont_Muestras_PMS=0;
         _MPromPMS_PM10=0;
         _MPromPMS_PM2_5=0;
         _MPromPMS_PM1=0;
         if(!_Pasivo)TimeMuestraPromedio->start();

         return  DataParticulado::StatusMuestras::EsperandoOPC;
    }
    else if(!OPC_Ok && !PMS_Ok) return  DataParticulado::StatusMuestras::EsperandoPMS_OPC;
}


void DataParticulado::InitMuestraDataPromedio()
{
    RA_cPMS->wakeUp();
    TimeMuestraPromedio->stop();
    bool ok=true;
    RA_cOPC->setFanAndLaserOn(&ok);
}

void DataParticulado::CheckfirstdataPMS()
{
    FirsDataPMS = true;
    _errorPMS->stop();
}


void DataParticulado::newDataOPC(float PM1, float PM2_5, float PM10)
{
    qDebug() << PM1 << PM2_5 << PM10;
    Promedio("PM10", PM10);   Promedio("PM2_5", PM2_5);   Promedio("PM1", PM1); AddMuestraOPC();
}


void DataParticulado::newDataPMS(uint16_t PM1, uint16_t PM2_5, uint16_t PM10)
{
    _errorPMS->start();
    if(FirsDataPMS){ Promedio("PM10",PM10);  Promedio("PM2_5",PM2_5);  Promedio("PM1",PM1); AddMuestraPMS();}
    FirsDataPMS=false;
}

void DataParticulado::initDataPMS()
{
    qDebug()<<"Inicialdo Toma de Muestras OPC y PMS en intevalos de "<< TimeMuestreo/1000 << "segundos, durante " << TimeMuestreo*Num_Muestras/1000<< "Segundos";
    RA_cOPC->ModeActive(TimeMuestreo);
}

