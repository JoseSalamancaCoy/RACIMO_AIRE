#ifndef DATAPARTICULADO_H
#define DATAPARTICULADO_H

#include "dataparticulado_global.h"

#include <QObject>
#include <QTimer>
#include <pms.h>
#include <opcn2.h>

class DATAPARTICULADOSHARED_EXPORT DataParticulado : public QObject
{
    Q_OBJECT

public:
    static const uint8_t Num_Muestras=12; //numero de muestras

    DataParticulado(OPCN2 *_RA_cOPC,PMS *_RA_cPMS,uint32_t tiempoMuestreo,uint32_t TiempoMuestraPromedio,QObject *parent = nullptr);
    virtual ~DataParticulado();
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
  void SetNumMuestras(size_t _Num_Muestras);
  void Muestra();
  void Activo(uint32_t TimeSleep);
  void Pasivo();
  StatusMuestras checkStatus();

  Struct_MPMS _MPMS;
  Struct_MOPC _MOPC;
  DATARACIMO _Data;


private:
    //size_t Num_Muestras; //numero de muestras
  uint32_t tiempoSLeep;
    bool _Pasivo;
    OPCN2 *RA_cOPC;
    PMS *RA_cPMS;
    QTimer *TimeMuestraPromedio;

    QTimer *_errorPMS;

    uint16_t TimeMuestreo;

    uint8_t Cont_Muestras_PMS;
    uint8_t Cont_Muestras_OPC;

    float _MPromPMS_PM10, _MPromPMS_PM2_5, _MPromPMS_PM1; //Promedio

    float _MPromOPC_PM10, _MPromOPC_PM2_5, _MPromOPC_PM1; //Promedio

    bool PMS_Ok;
    bool OPC_Ok;
    bool GPS_Ok;
    bool FirsDataPMS;


private slots:
    void InitMuestraDataPromedio();
    void CheckfirstdataPMS();
    void newDataOPC(float PM1, float PM2_5, float PM10);
    void newDataPMS(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);
    void initDataPMS();

signals:
    void DataOk();
    void DataOkPMS(float,float,float);
    void DataOkOPC(float,float,float);

};

#endif // DATAPARTICULADO_H
