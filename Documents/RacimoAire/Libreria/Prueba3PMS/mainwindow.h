#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include  <QDebug>
#include <pms.h>

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

private:
    Ui::MainWindow *ui;
    Crpigpio *GPIO;
    PMS *PMSSensor;
};

#endif // MAINWINDOW_H
