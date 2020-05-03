#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <PMS.h>

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

    void newDataPMS(uint16_t PM_1_0, uint16_t PM_2_5, uint16_t PM_10);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_ModActivo_clicked();

    void on_ModActivo_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Crpigpio *GPIO;
    PMS *PMSSensor;
    PMS::DATA DATAA;

};

#endif // MAINWINDOW_H
