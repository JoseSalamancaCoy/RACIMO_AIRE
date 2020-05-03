#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RA_cGPIO = new Crpigpio;
    RA_cADC = new ADS1115(RA_cGPIO);
    RA_cADC->setGain(GAIN_TWOTHIRDS);
    //RA_cADC->SetMode(MODE_CONTIN);       // Continuous conversion mode
    RA_cADC->setRate(RATE_128);          // 128SPS (default)
    RA_cADC->setOSMode(OSMODE_SINGLE);   // Set to start a single-conversion
    RA_cADC->Measure_SingleEnded(0);

}

MainWindow::~MainWindow()
{
    RA_cGPIO->CloseI2C();
    delete RA_cGPIO;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}



void MainWindow::on_pushButton_2_clicked()
{
    int16_t Muestra = RA_cADC->Measure_SingleEnded(0);
    qDebug() << QString("Canal1 = %1   ...  %2  ... %3 ").arg(Muestra).arg(Muestra,0,2).arg(Muestra,0,16);
}

void MainWindow::on_pushButton_3_pressed()
{
    qDebug() << "Dataaaa " ;

    int16_t Muestra = RA_cADC->Measure_SingleEnded(0);
    double Voltaje = (Muestra*6.144/32767);
    qDebug() << Voltaje<< "\n\n";


    Muestra = RA_cADC->Measure_SingleEnded(1);
    Voltaje = (Muestra*6.144/32767);
    qDebug() << Voltaje<< "\n\n";

    Muestra = RA_cADC->Measure_SingleEnded(2);
    Voltaje = (Muestra*6.144/32767);
    qDebug() << Voltaje<< "\n\n";

    Muestra = RA_cADC->Measure_SingleEnded(3);
    Voltaje = (Muestra*6.144/32767);
    qDebug() << Voltaje<< "\n\n\n\n";
}
