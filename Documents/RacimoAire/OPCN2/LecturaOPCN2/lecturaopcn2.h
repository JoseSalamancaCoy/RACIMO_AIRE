# ifndef LECTURAOPCN2_H
#define LECTURAOPCN2_H

#include <QMainWindow>
#include "opcn2.h"
#include "opcn2_data.h"
namespace Ui {
class LecturaOPCN2;
}

class LecturaOPCN2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LecturaOPCN2(QWidget *parent = nullptr);
    ~LecturaOPCN2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void newDataOPC(float PM1, float PM2_5, float PM10);

private:
    Ui::LecturaOPCN2 *ui;
    OPCN2 *RA_cOPC;
    OPCN2Data OPCDATA;
    Crpigpio *RA_cGPIO;
};

#endif // LECTURAOPCN2_H
