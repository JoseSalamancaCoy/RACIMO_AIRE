#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QThread>
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    while(1)
    {
        system("ps -e | grep RacimoAire3 | wc -l > /home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/AppCorriendo");
        QFile file("/home/pi/RACIMOAIRE/DataIntercambio/LogsSystem/AppCorriendo");
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QByteArray APP = file.readAll();
            APP.chop(1);
            if(!APP.toInt()) system("sudo RacimoAire3 &");
            file.close();
        }
        QThread::sleep(10);
    }
    return 0;
}
