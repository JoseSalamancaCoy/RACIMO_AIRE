#ifndef LOGSSYSTEM_H
#define LOGSSYSTEM_H

#include "logssystem_global.h"
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QFile>
#include <QStringList>
#include <QRegularExpression>

class LogsSystem  : public QThread
{
    Q_OBJECT
public:
    LogsSystem(QObject *parent=nullptr);
    enum Logs{ _ObtenerTemperatura, _ObtenerRAM, _ObtenerSOCKET, _ObtenerProcesos, _ObtenerStatusWIFI, _ObtenerEspacioDisco};

    void Restart();
    void stop();
    void CheckTemperatura();
    void CheckRAM();
    void CheckSOCKET();
    void CheckProcesos();
    void CheckStatusWIFI();
    void CheckESpacioDisco();
protected:
    void run();

public slots:
    void doWork(int accion);


signals:
    void resultReady(const QString &result);
    void SignalTemperatura(float temperatura);
    void SignalRAM(float RAM);
    void SignalSOCKET(int SOCKET);
    void SignalProcesos(int Procesos);
    void SignalStatusWIFI(bool StatusWIFI);
    void SignalEspacioDisco( int EspacioDisco);


private:
    float ObtenerTemperatura();
    float ObtenerRAM();
    int ObtenerSOCKET();
    int ObtenerProcesos();
    bool ObtenerStatusWIFI();
    int ObtenerEspacioDisco();

    bool Stop;

    bool Temperatura;
    bool RAM;
    bool SOCKET;
    bool Procesos;
    bool StatusWIFI;
    bool EspacioDisco;

    QString AddrBase ="/home/pi/Job/Estaciones/RacimoAire/";
};

#endif // LOGSSYSTEM_H
