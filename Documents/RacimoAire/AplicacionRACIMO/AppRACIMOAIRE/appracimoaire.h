#ifndef APPRACIMOAIRE_H
#define APPRACIMOAIRE_H

#include <nextion.h>
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
#include <racimohttp.h>
#include "logssystem.h"
#include "adminlogssystem.h"


#define GPIOPMSSet 18
#define GPIOPMSReSet 24
#define GPIOPMSRX 23
#define GPIOGPSRX 25
#define GPIOGPSPPS 20
namespace Ui {
class appRacimoAire;
}
class Nextion;

class appRacimoAire : public QMainWindow
{
    Q_OBJECT

public:
    explicit appRacimoAire(QWidget *parent = 0);
    ~appRacimoAire();

private:
    Ui::appRacimoAire *ui;
    OPCN2 *RA_cOPC;
    GPS *RA_cGPS;
    PMS *RA_cPMS;
    PMS::DATA DATAPMS;
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






    char buffer[100];
    char buffer2[100];

    QDateTime DateTime;
    QString DateTimeStr;
    QString addrarchivo;
    uint16_t TimeMuestreo;
    QTimer *TimeMuestraPromedio;
    QTimer *TimeMuestraPromedioBME;

    QTime Time;


private slots:
    void NewDataBME();
    void newDataGPS( float  latitude, float longitude, float latitudeDegrees, float longitudeDegrees, int32_t latitude_fixe , int32_t longitude_fixed);
    void DataOk(DataParticulado::DATARACIMO *_Data, DataParticulado::Struct_MOPC *_MOPC, DataParticulado::Struct_MPMS *_MPMS);
};

#endif // APPRACIMOAIRE_H
