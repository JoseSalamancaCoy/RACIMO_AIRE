#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QDebug>
#include <QThread>


#define GPIOSet 13
#define GPIOReSet 5
#define GPIORX 6

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GPIO = new Crpigpio;
    PMSSensor = new PMS(GPIO,GPIOSet, GPIOReSet, GPIORX, 1000);
    PMSSensor->wakeUp();

    connect(PMSSensor, SIGNAL(newData(uint16_t,uint16_t,uint16_t)),this, SLOT(newDataPMS(uint16_t,uint16_t,uint16_t)));
}

MainWindow::~MainWindow()
{
    PMSSensor->sleep();
    delete PMSSensor;
    delete GPIO,
    delete ui;
}

void MainWindow::newDataPMS(uint16_t PM_1_0, uint16_t PM_2_5, uint16_t PM_10)
{
    QString comando= "clear";
    system(qPrintable(comando));
    qDebug() << "Data PM1 ="<< PM_1_0;
    qDebug() << "Data PM2.5 ="<< PM_2_5;
    qDebug() << "Data PM10 ="<< PM_10;


}

void MainWindow::on_pushButton_clicked()
{
       qDebug() << "Data PM10 ="<<PMSSensor->Data.PM_SP_UG_10_0;
       qDebug() << "Data PM2.5 ="<<PMSSensor->Data.PM_SP_UG_2_5;
       qDebug() << "Data PM1 ="<<PMSSensor->Data.PM_SP_UG_1_0;
}

void MainWindow::on_pushButton_2_clicked()
{
    PMSSensor->sleep();
}

void MainWindow::on_pushButton_3_clicked()
{
        PMSSensor->wakeUp();
        qDebug() << "Esperando 30 segundos para toma de datos ....";
        //QThread::msleep(30000);
       qDebug() << "Espera finalizada";
}

void MainWindow::on_pushButton_4_clicked()
{
    PMSSensor->Reset();
}

void MainWindow::on_ModActivo_clicked()
{
    PMSSensor->activeMode();
}

void MainWindow::on_ModActivo_2_clicked()
{
    PMSSensor->passiveMode();
}

void MainWindow::on_pushButton_5_clicked()
{
    PMSSensor->requestRead();
}
