#include "appracimoaire.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    appRacimoAire w;
    w.show();

    return a.exec();
}
