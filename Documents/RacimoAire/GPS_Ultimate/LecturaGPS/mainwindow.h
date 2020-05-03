#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "crpigpio.h"
#include "Adafruit_GPS.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:

    Ui::MainWindow *ui;
    Crpigpio *RA_cGPIO;
    Adafruit_GPS *RA_cGPS;
    QTimer *timer;

private slots:
    void newDataGPS( uint8_t hour, uint8_t minute,  uint8_t seconds, uint8_t year, uint8_t month,  uint8_t day,  uint16_t milliseconds,  float latitude, float longitude);


};

#endif // MAINWINDOW_H
