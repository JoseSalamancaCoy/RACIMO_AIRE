#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RA_cGPIO = new Crpigpio;
    RA_cBME280 = new Adafruit_BME280(RA_cGPIO,0x77);
}

MainWindow::~MainWindow()
{
    delete RA_cBME280;
    delete RA_cGPIO;
    delete ui;
}

void MainWindow::on_Temperatura_pressed()
{
    RA_cBME280->takeForcedMeasurement();
    qDebug() << "Temperatura = "<< RA_cBME280->readTemperature();
}

void MainWindow::on_Humedad_pressed()
{
    RA_cBME280->takeForcedMeasurement();
    qDebug() <<"Humedad = "<<RA_cBME280->readHumidity();
}

void MainWindow::on_Presion_pressed()
{
    RA_cBME280->takeForcedMeasurement();
    qDebug() <<"Presion = "<< RA_cBME280->readPressure()/100;
}
