#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QDebug>
#include <datajson.h>
#include <racimohttp.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    DataJson *_DataJson;




private slots:
    void on_pushButton_pressed();

    void on_WriteJson_pressed();

    void on_ReadJson_pressed();

    void on_GetTime_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
