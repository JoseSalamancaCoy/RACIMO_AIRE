#ifndef DIALOG_H
#define DIALOG_H

#include <QObject>
#include <QDialog>
#include <crpigpio.h>
#include <pms.h>
#include <opcn2.h>
#include <QTimer>
#include <dataparticulado.h>
#include <logssystem.h>
#include <datajson.h>
#include <datajson2.h>
#include <cdatetimer.h>

#include <curl/curl.h>


#define GPIOPMSSet1 5
#define GPIOPMSReSet1 27
#define GPIOPMSRX1 22

#define GPIOPMSSet2 2
#define GPIOPMSReSet2 3
#define GPIOPMSRX2 4

#define GPIOPMSSet3 14
#define GPIOPMSReSet3 23
#define GPIOPMSRX3 15

#define GPIOPMSSet4 24
#define GPIOPMSReSet4 12
#define GPIOPMSRX4 25

#define GPIOPMSSet5 26
#define GPIOPMSReSet5 6
#define GPIOPMSRX5 13



class QObject;


class Dialog : public QObject
{
    Q_OBJECT

public:
    explicit Dialog(QObject *parent = 0);
    ~Dialog();

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

    LogsSystem *LogsThread;

    Crpigpio *RA_cGPIO1;
    Crpigpio *RA_cGPIO2;
    Crpigpio *RA_cGPIO3;
    Crpigpio *RA_cGPIO4;
    Crpigpio *RA_cGPIO5;

    PMS *RA_cPMS1;
    PMS *RA_cPMS2;
    PMS *RA_cPMS3;
    PMS *RA_cPMS4;
    PMS *RA_cPMS5;

    OPCN2 *RA_cOPC1;
    OPCN2 *RA_cOPC2;
    OPCN2 *RA_cOPC3;
    OPCN2 *RA_cOPC4;
    OPCN2 *RA_cOPC5;

    DataParticulado *RA_cDataParticulado1;
    DataParticulado *RA_cDataParticulado2;
    DataParticulado *RA_cDataParticulado3;
    DataParticulado *RA_cDataParticulado4;
    DataParticulado *RA_cDataParticulado5;

    DataJson *_DataJson;
    DataJson2 *_DataJson2;
    CDateTimer *DateTimer;

    uint32_t Delta_muestra_muestra;

    bool CheckLectura[5];



private:
    QTimer *Timer;
    QTimer *TimeDataLogs;
    QTimer *TimeoutLectura;
    bool _timeoutlectura;
    Metadatos MetaData;
    bool NewData;

    float List_PMS_PM1[5];     float List_PMS_PM2_5[5];     float List_PMS_PM10[5];
    float List_OPC_PM1[5];     float List_OPC_PM2_5[5];     float List_OPC_PM10[5];
    bool List_Check_PMS[5];  bool List_Check_OPC[5];
    Transmision();
    void SabeDataCsv();
    void RstData();
    void POSTHttp(char *charjson);
    void SetHora();


private slots:
    void setTimeoutlectura();

    void Muestra();

    void DataOk1();
    void DataParticuladoOkPMS1(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataParticuladoOkOPC1(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataOkPMS1(float PM1, float PM2_5, float PM10);
    void DataOkOPC1(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);


    void DataOk2();
    void DataParticuladoOkPMS2(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataParticuladoOkOPC2(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataOkPMS2(float PM1, float PM2_5, float PM10);
    void DataOkOPC2(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);

    void DataOk3();
    void DataParticuladoOkPMS3(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataParticuladoOkOPC3(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataOkPMS3(float PM1, float PM2_5, float PM10);
    void DataOkOPC3(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);


    void DataOk4();
    void DataParticuladoOkPMS4(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataParticuladoOkOPC4(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataOkPMS4(float PM1, float PM2_5, float PM10);
    void DataOkOPC4(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);


    void DataOk5();
    void DataParticuladoOkPMS5(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataParticuladoOkOPC5(float PM1Promedio, float PM2_5Promedio, float PM10Promedio);
    void DataOkPMS5(float PM1, float PM2_5, float PM10);
    void DataOkOPC5(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);

    void Show();

    void DataLogs();
    void SlotTemperatura(float temperatura);
    void SlotRAM(float RAM);
    void SlotSOCKET(int SOCKET);
    void SlotProcesos(int Procesos);
    void SlotStatusWIFI(bool StatusWIFI);
    void SlotEspacioDisco( int EspacioDisco);

};





#endif // DIALOG_H
