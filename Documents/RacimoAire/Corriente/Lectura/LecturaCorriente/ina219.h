#ifndef INA219_H
#define INA219_H

#include <QMainWindow>
#include <crpigpio.h>
#include <adafruit_ina219.h>
namespace Ui {
class INA219;
}

class INA219 : public QMainWindow
{
    Q_OBJECT

public:
    explicit INA219(QWidget *parent = 0);
    ~INA219();

private slots:
    void on_pushButton_pressed();

private:
    Ui::INA219 *ui;
    Crpigpio *RA_cGPIO;
    Adafruit_INA219 *CorrienteINA219;
};

#endif // INA219_H
