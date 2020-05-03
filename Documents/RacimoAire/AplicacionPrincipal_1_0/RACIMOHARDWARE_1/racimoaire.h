#ifndef RACIMOAIRE_H
#define RACIMOAIRE_H

#include <QMainWindow>
#include "dataracimoaire.h"
#include <gps.h>
#include <pms.h>
#include <opcn2.h>
#include <crpigpio.h>
#include <QFile>
#include <QDateTime>
namespace Ui {
class RACIMOAIRE;
}

class RACIMOAIRE : public QMainWindow
{
    Q_OBJECT

public:
    explicit RACIMOAIRE(QWidget *parent = 0);
    ~RACIMOAIRE();
private:
    Ui::RACIMOAIRE *ui;
    OPCN2 *RA_cOPC;
    GPS *RA_cGPS;
    PMS *RA_cPMS;
    PMS::DATA DATAPMS;
    DataRacimoAire *RA_cData;
    Crpigpio *RA_cGPIO;

    QDateTime DateTime;
    QString DateTimeStr;
    QString addrarchivo;
    uint16_t TimeMuestreo;
    QTimer *TimeMuestraPromedio;
    QTime Time;

private slots:
    void InitMuestraDataPromedio();
    void newDataOPC(float PM1, float PM2_5, float PM10);
    void newDataGPS( float  latitude, float longitude, float latitudeDegrees, float longitudeDegrees, int32_t latitude_fixe , int32_t longitude_fixed);
    void newDataPMS(uint16_t PM1, uint16_t PM2_5, uint16_t PM10);
    void initDataPMS();
    void DataOk(DataRacimoAire::DATARACIMO *_Data, DataRacimoAire::Struct_MOPC *_MOPC, DataRacimoAire::Struct_MPMS *_MPMS);
};

#endif // RACIMOAIRE_H
