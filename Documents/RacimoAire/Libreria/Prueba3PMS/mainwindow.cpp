#include "mainwindow.h"
#include "ui_mainwindow.h"
#define GPIOSet 16
#define GPIOReSet 12
#define GPIORX 26
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GPIO = new Crpigpio;
    PMSSensor = new PMS(GPIO,GPIOSet, GPIOReSet, GPIORX);
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
