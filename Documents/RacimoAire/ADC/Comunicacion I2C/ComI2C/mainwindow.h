#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <crpigpio.h>
#include <ads1115.h>
#include <QDebug>
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_pressed();

private:
    Ui::MainWindow *ui;
    Crpigpio *RA_cGPIO;
    ADS1115 *RA_cADC;
    QTime *Time;

};

#endif // MAINWINDOW_H
