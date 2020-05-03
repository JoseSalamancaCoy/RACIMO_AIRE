#include "ina219.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    INA219 w;
    w.show();

    return a.exec();
}
