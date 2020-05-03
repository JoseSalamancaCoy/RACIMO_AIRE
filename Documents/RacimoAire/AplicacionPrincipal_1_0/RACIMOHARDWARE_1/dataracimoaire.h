#ifndef DATARACIMOAIRE_H
#define DATARACIMOAIRE_H

#include <QObject>
#include <QTimer>
#include <pms.h>
#include <opcn2.h>
#include <crpigpio.h>
#include <iostream>

class DataRacimoAire : public QObject
{
    Q_OBJECT

public:
    DataRacimoAire(OPCN2 *_RA_cOPC,PMS *_RA_cPMS,QWidget *parent = Q_NULLPTR);
    virtual ~DataRacimoAire();
    static const uint8_t Num_Muestras=12; //numero de muestras
    enum StatusMuestras {EsperandoPMS_OPC, EsperandoPMS, EsperandoOPC, MuestrasCompletas};

    struct DATARACIMO {  //Structura de datos PMS
     // Particulas estandar, CF=1
         float PMS_PM_1;
         float PMS_PM_2_5;
         float PMS_PM_10;
         float OPC_PM_1;
         float OPC_PM_2_5;
         float OPC_PM_10;
         float LatitudDegrees;
         float LongitudDegrees;
   };    
    struct Struct_MPMS {uint16_t PM10[Num_Muestras]; uint16_t PM2_5[Num_Muestras]; uint16_t  PM1[Num_Muestras];}; //Muestras
    struct Struct_MOPC { float PM10[Num_Muestras];  float PM2_5[Num_Muestras]; float PM1[Num_Muestras]; }; //Muestras

  void Promedio(QString Variable, uint16_t Valor);  //Promedio para PMS
  void Promedio(QString Variable, float Valor);   //Promedio para OPC
  void AddMuestraPMS();
  void AddMuestraOPC();
  void ResetData();
  StatusMuestras checkStatus();

private:
    OPCN2 *RA_cOPC;
    PMS *RA_cPMS;
    QTimer *TimeMuestraPromedio;
    uint16_t TimeMuestreo;


    uint8_t Cont_Muestras_PMS;
    uint8_t Cont_Muestras_OPC;

    Struct_MPMS _MPMS;
    float _MPromPMS_PM10, _MPromPMS_PM2_5, _MPromPMS_PM1; //Promedio

    Struct_MOPC _MOPC;
    float _MPromOPC_PM10, _MPromOPC_PM2_5, _MPromOPC_PM1; //Promedio

    DATARACIMO _Data;
    bool PMS_Ok;
    bool OPC_Ok;
    bool GPS_Ok;

private slots:
    void InitMuestraDataPromedio();
    void newDataOPC(float PM1, float PM2_5, float PM10);
    void newDataPMS(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);
    void initDataPMS();

signals:
    void DataOk(DataRacimoAire::DATARACIMO *_Data, DataRacimoAire::Struct_MOPC *_MOPC, DataRacimoAire::Struct_MPMS *_MPMS);

};

#endif // DATARACIMOAIRE_H
