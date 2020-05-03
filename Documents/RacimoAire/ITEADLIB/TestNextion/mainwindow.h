#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <nextion.h>
#include <nextionraspberrypi.h>
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
    void on_pushButton_pressed();

    void on_spinBox_valueChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Crpigpio *GPIO;
    NextionRaspberrypi *Serial;
    NexDSButton *bt0;
    NexProgressBar *j0;
    NexText *txt_temp;
    NexText *txt_hum;
    QString Valor;

    char buffer[100];
    char buffer2[100];

};

#endif // MAINWINDOW_H
