#include "racimoaire.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RACIMOAIRE w;
    w.show();

    return a.exec();
}
