#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <crpigpio.h>
#include "Adafruit_BME280.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Temperatura_pressed();

    void on_Humedad_pressed();

    void on_Presion_pressed();

private:
    Ui::MainWindow *ui;
    Crpigpio *RA_cGPIO;
    Adafruit_BME280 *RA_cBME280;
};

#endif // MAINWINDOW_H
