#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QString>

#define GPSRx 18
#define GPSPPS 17
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RA_cGPIO = new Crpigpio;
    RA_cGPS = new Adafruit_GPS(RA_cGPIO, 18, 17);
    connect(RA_cGPS, SIGNAL(newData(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint16_t,float,float)),this, SLOT(newDataGPS(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint16_t,float,float)));
}

MainWindow::~MainWindow()
{
    delete ui;
    RA_cGPIO->CloseSerialgpio(18);
    delete RA_cGPS;
    delete RA_cGPIO;

}

void MainWindow::newDataGPS(uint8_t hour, uint8_t minute, uint8_t seconds, uint8_t year, uint8_t month, uint8_t day, uint16_t milliseconds, float latitude, float longitude)
{
    qDebug() <<"Aja y entonces ?";
    QString comando= "clear";
    system(qPrintable(comando));
    qDebug() << "year = " <<  year ;
    qDebug() << "month = " <<  month ;
    qDebug() << "day = " <<  day ;
    qDebug() << "hour = " <<  hour ;
    qDebug() << "minute = " <<  minute ;
    qDebug() << "seconds = " <<  seconds ;
    qDebug() << "milliseconds = " <<  milliseconds ;
    qDebug() << "latitude = " <<  latitude ;
    qDebug() << "longitude = " <<  longitude ;
    qDebug() <<"altitude = " << RA_cGPS->altitude;
    qDebug() <<"fixquality = " << RA_cGPS->fixquality;
    qDebug() <<"geoidheight = " << RA_cGPS->geoidheight;
    qDebug() <<"speed = " << RA_cGPS->speed;
    qDebug() <<"Latitud" << RA_cGPS->latitudeDegrees;
    qDebug() <<"Latitud" << RA_cGPS->longitudeDegrees;



}

