#ifndef RACIMO3_H
#define RACIMO3_H


#include <QObject>
#include <crpigpio.h>
#include <pms.h>
#include <opcn2.h>
#include <QTimer>
#include <dataparticulado.h>
#include <logssystem.h>
#include <datajson2.h>
#include <cdatetimer.h>

#include <gps.h>
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <adafruit_bme280.h>
#include <adafruit_ina219.h>
#include <ads1115.h>
#include <nextion.h>


#include <curl/curl.h>
#define GPIOPMSSet 18
#define GPIOPMSReSet 24
#define GPIOPMSRX 23
#define GPIOGPSRX 25
#define GPIOGPSPPS 12

#define GPIOWiFi 20
#define GPIOTransmision 16
#define GPIOButton 21





class Racimo3 :public QObject
{
    Q_OBJECT
public:
    explicit Racimo3(QObject *parent = nullptr);
    virtual ~Racimo3();

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
    struct DataGPS
    {
        QString longitud;
        QString latitud;
        float altura;
        uint8_t fix;
        int hora;
        int minuto;
        int segundo;
    };


    LogsSystem *LogsThread;

    Crpigpio *RA_cGPIO1;
    Crpigpio *RA_cGPIO2;
    Crpigpio *RA_cGPIO3;

    PMS *RA_cPMS;
    OPCN2 *RA_cOPC;
    GPS *RA_cGPS;
    ADS1115 *RA_cGADC;
    Adafruit_INA219 *RA_cCorriente;
    Adafruit_BME280 *RA_cBME280;
    DataParticulado *RA_cDataParticulado1;

    DataJson2 *_DataJson2;
    CDateTimer *DateTimer;
    QTime TimePushButton;


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

    uint32_t Delta_muestra_muestra;

    bool CheckLectura[2];

private:
    DataGPS _DataGPS;
    QTimer *Timer;
    QTimer *TimeDataLogs;
    QTimer *TimeoutLectura;
    QTimer *TimerAlertWifi;
    QTimer *BlinkLeds;
    uint8_t contReboot_rstApp;

    bool blinkLed;

    bool InitAPP;
    bool _timeoutlectura;
    bool NewData;
    bool AlertWifi;
    bool AlertRAM;
    bool AlertTemperatura;
    bool AlertPMS;
    bool AlertOPC;

    bool ShutdownManual;
    bool RebootManual;
    bool _CerrarApp;
    bool StateBME280;
    bool StateINA219;
    bool StateADS1115;

    Metadatos MetaData;

    float PMS_PM1;     float PMS_PM2_5;     float PMS_PM10;
    float OPC_PM1;     float OPC_PM2_5;     float OPC_PM10;
    bool Check_PMS;  bool Check_OPC;

    bool Transmision();
    void SabeDataCsv();
    void RstData();
    bool POSTHttp(char *charjson);
    void SetHora();

private slots:
    void checkRst_App_Raspi();
    void OnISR(int gpio,int level,quint32 timeout);
    void Blink();
    void check_InitAPP();
    void check_AlertRAM();
    void check_AlertTemperatura();
    void ReinicioRaspi();
    void ShutdownRaspi();
    void CerrarApp();

    void timeoutAlertWifi();
    void newDataGPS();
    void DataOk1();
    void DataParticuladoOkPMS1(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataParticuladoOkOPC1(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void setTimeoutlectura();
    void Muestra();
    void Show();

    void DataLogs();
    void SlotTemperatura(float temperatura);
    void SlotRAM(float RAM);
    void SlotSOCKET(int SOCKET);
    void SlotProcesos(int Procesos);
    void SlotStatusWIFI(bool StatusWIFI);
    void SlotEspacioDisco( int EspacioDisco);


};

#endif // RACIMO3_H
