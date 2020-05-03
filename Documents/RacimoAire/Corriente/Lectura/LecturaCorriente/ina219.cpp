#include "ina219.h"
#include "ui_ina219.h"
#include <QDebug>

INA219::INA219(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::INA219)
{
    ui->setupUi(this);
    RA_cGPIO = new Crpigpio;
    CorrienteINA219 = new Adafruit_INA219(RA_cGPIO);
    CorrienteINA219->setCalibration_32V_1A();
}

INA219::~INA219()
{
    delete ui;
}

void INA219::on_pushButton_pressed()
{
    float shuntVoltage =0;
    float busvoltage=0;
    float current_mA=0;
    float loadvoltage =0;
    float power_mw =0;

    shuntVoltage = CorrienteINA219->getShuntVoltage_mV();
    busvoltage = CorrienteINA219->getBusVoltage_V();
    current_mA =CorrienteINA219->getCurrent_mA();
    power_mw = CorrienteINA219->getPower_mW();
    loadvoltage = busvoltage + (shuntVoltage/1000);
    qDebug() << QString("Bus Voltage %1 V").arg(busvoltage);
    qDebug() << QString("Shunt Voltage %1 mV").arg(shuntVoltage);
    qDebug() << QString("Load Voltage %1 V").arg(loadvoltage);
    qDebug() << QString("Current %1 mA").arg(current_mA);
    qDebug() << QString("Power %1 mW").arg(power_mw);
    qDebug() << "\n\n";


}
