#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{

}

void MainWindow::on_WriteJson_pressed()
{

    _DataJson->SetDato(_DataJson->Humedad, 70);
    _DataJson->SetDato(_DataJson->Presion, 900);
    _DataJson->SetDato(_DataJson->Temperatura, 21);
    _DataJson->SetDato(_DataJson->PM10, 1);
    _DataJson->SetDato(_DataJson->PM2_5, 4);
    _DataJson->WriteJson();
}

void MainWindow::on_ReadJson_pressed()
{

    RacimoHttp Comunicacion;
    QStringList _DataJsonString;
    qDebug()<<_DataJsonString;
    qDebug() <<_DataJson->readJson(&_DataJsonString);

    for(int i=0;i<_DataJsonString.length() ; i++)
    {
        std::string STR = QString(_DataJsonString.operator [](i)).toStdString();
        char String[1000];
        sprintf(String,"%s",STR.c_str());
        Comunicacion.POSTHttp(&String[0]);
        qDebug() << String;
    }
}

void MainWindow::on_GetTime_pressed()
{
    RacimoHttp Comunicacion;
    Comunicacion.SetHora();
}
