#ifndef RACIMOAIRE2_H
#define RACIMOAIRE2_H

#include <QMainWindow>



#include <dataparticulado.h>
#include <gps.h>
#include <pms.h>
#include <opcn2.h>
#include <crpigpio.h>
#include <QFile>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <datajson.h>
#include <adafruit_bme280.h>
#include <adafruit_ina219.h>
#include <ads1115.h>
#include <curl/curl.h>
#include <nextion.h>

#include <racimohttp.h>
#include "logssystem.h"
#include "adminlogssystem.h"

#define GPIOPMSSet 18
#define GPIOPMSReSet 24
#define GPIOPMSRX 23
#define GPIOGPSRX 25
#define GPIOGPSPPS 20
namespace Ui {
class RacimoAire2;
}
class LogsSystem;
class RacimoAire2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit RacimoAire2(QWidget *parent = 0);
    ~RacimoAire2();

private:
    Ui::RacimoAire2 *ui;

    enum Logs{ _ObtenerTemperatura, _ObtenerRAM, _ObtenerSOCKET, _ObtenerProcesos, _ObtenerStatusWIFI, _ObtenerEspacioDisco};
    struct Metadatos
    {
        float _Temperatura;
        float _RAM; //Porsetnaje
        int _SOCKET;
        int _Procesos;
        bool _StatusWIFI;
        int _EspacioDisco; //Porsentaje
    };

    OPCN2Data DataOPC;
    PMS::DATA DATAPMS;



    OPCN2 *RA_cOPC;
    GPS *RA_cGPS;
    PMS *RA_cPMS;
    DataParticulado *RA_cData;
    Crpigpio *RA_cGPIO;
    Crpigpio *RA_cGPIO2;
    Crpigpio *RA_cGPIO3;
    DataJson *_DataJson;
    ADS1115 *RA_cGADC;
    Adafruit_INA219 *RA_cCorriente;
    Adafruit_BME280 *RA_cBME280;



    NextionRaspberrypi *Serial;
    NexDSButton *bt0;
    NexProgressBar *j0;
    NexText *txt_temp;
    NexText *txt_Presion;
    NexText *txt_hum;
    NexText *txt_longitud;
    NexText *txt_latitud;
    NexText *txt_Altitud;
    NexText *txt_Fix;
    NexText *txt_wifi;
    NexText *txt_PM25_P;
    NexText *txt_PM25_O;
    NexText *txt_PM10_P;
    NexText *txt_PM10_0;

    LogsSystem *LogsThread;

    char buffer[100];
    char buffer2[100];

    QDateTime DateTime;
    QString DateTimeStr;
    QString addrarchivo;
    uint16_t TimeMuestreo;
    QTimer *TimeMuestraPromedio;
    QTimer *TimeMuestraPromedioBME;
    QTime Time;
    Metadatos MetaData;


private slots:
    void NewDataBME();
    void newDataGPS();
    void newDataOPC(float PM1, float PM2_5, float PM10);
    void newDataPMS(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);
    void initDataPMS();

    void DataLogs();
    void SlotTemperatura(float temperatura);
    void SlotRAM(float RAM);
    void SlotSOCKET(int SOCKET);
    void SlotProcesos(int Procesos);
    void SlotStatusWIFI(bool StatusWIFI);
    void SlotEspacioDisco( int EspacioDisco);


};

#endif // RACIMOAIRE2_H
