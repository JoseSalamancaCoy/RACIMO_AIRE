#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GPIO = new Crpigpio;
    Serial =new NextionRaspberrypi(GPIO,9600);
    nexInit(Serial);
    j0 = new NexProgressBar(Serial,0,6,"j0");
    txt_hum = new NexText(Serial,0,3,"t2");
    txt_temp = new NexText(Serial,0,5,"t0");
    bt0 = new NexDSButton(Serial,0,7,"bt0");
}

MainWindow::~MainWindow()
{
    delete j0;
    delete txt_hum;
    delete txt_temp;
    delete bt0;
    delete Serial;
    delete GPIO;
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    memset(buffer,0,sizeof(buffer));
    j0->setValue(Valor.toLong());
    txt_hum->setText(Valor.toStdString().c_str());
    txt_temp->setText(Valor.toStdString().c_str());



}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    Valor =arg1;
}
