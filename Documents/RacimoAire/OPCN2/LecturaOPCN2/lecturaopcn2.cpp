#include "lecturaopcn2.h"
#include "ui_lecturaopcn2.h"
#include <QDebug>
LecturaOPCN2::LecturaOPCN2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LecturaOPCN2)
{
    ui->setupUi(this);
    RA_cGPIO = new Crpigpio;
    RA_cOPC = new OPCN2(RA_cGPIO);
    RA_cOPC->initialize();
    connect(RA_cOPC, SIGNAL(newData(float,float,float)),this,SLOT(newDataOPC(float,float,float)));
    bool ok=true;
    RA_cOPC->setFanAndLaserOn(&ok);
    RA_cOPC->ModeActive(1000);

}

LecturaOPCN2::~LecturaOPCN2()
{
    RA_cOPC->setFanAndLaserOff();
    delete RA_cOPC;
    delete RA_cGPIO;
    delete ui;
}

void LecturaOPCN2::on_pushButton_clicked()
{
    bool ok=true;
    RA_cOPC->setFanAndLaserOn(&ok);
}

void LecturaOPCN2::on_pushButton_2_clicked()
{
    bool ok=true;
    RA_cOPC->setFanAndLaserOff(&ok);
}

void LecturaOPCN2::on_pushButton_3_clicked()
{
    bool ok=true;
    OPCDATA = RA_cOPC->getHistogramData(&ok);
    qDebug() << "PM10= " << OPCDATA.PM10;
    qDebug() << "PM2.5= " << OPCDATA.PM2_5;
    qDebug() << "PM1= " << OPCDATA.PM1;
    qDebug() << "pressure= " << OPCDATA.pressure;
    qDebug() << "temperature= " << OPCDATA.temperature;
    qDebug() << "NumHistograma= " << OPCDATA.NumHistogramBins;
    qDebug() << "samplePeriod=" << OPCDATA.samplePeriod << "\n\n\n";
}

void LecturaOPCN2::newDataOPC(float PM1, float PM2_5, float PM10)
{
    QString comando= "clear";
    system(qPrintable(comando));
    qDebug() << "Data PM1 ="<< PM1;
    qDebug() << "Data PM2.5 ="<< PM2_5;
    qDebug() << "Data PM10 ="<< PM10;

}
