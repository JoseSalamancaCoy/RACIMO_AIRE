#include "adminlogssystem.h"




AdminLogsSystem::AdminLogsSystem(QObject *parent): QObject(parent) {
    logsSystem = new LogsSystem;
    logsSystem->moveToThread(&logsSystemThread);
    connect(&logsSystemThread, &QThread::finished, logsSystem, &QObject::deleteLater);
    connect(this, &AdminLogsSystem::operate, logsSystem, &LogsSystem::doWork);
    connect(logsSystem, &LogsSystem::resultReady, this, &AdminLogsSystem::handleResults);

    connect(logsSystem, &LogsSystem::SignalTemperatura, this, &AdminLogsSystem::SlotTemperatura);
    connect(logsSystem, &LogsSystem::SignalRAM, this, &AdminLogsSystem::SlotRAM);
    connect(logsSystem, &LogsSystem::SignalProcesos, this, &AdminLogsSystem::SignalProcesos);
    connect(logsSystem, &LogsSystem::SignalSOCKET, this, &AdminLogsSystem::SignalSOCKET);
    connect(logsSystem, &LogsSystem::SignalStatusWIFI, this, &AdminLogsSystem::SignalStatusWIFI);
    connect(logsSystem, &LogsSystem::SignalEspacioDisco, this, &AdminLogsSystem::SlotEspacioDisco);

    logsSystemThread.start();
    //initHilo(accion);
}

AdminLogsSystem::~AdminLogsSystem() {
}

void AdminLogsSystem::SlotTemperatura(float temperatura)
{
    emit SignalTemperatura(temperatura);
}

void AdminLogsSystem::SlotRAM(QString RAM)
{
    emit SignalRAM(RAM);
}

void AdminLogsSystem::SlotSOCKET(int SOCKET)
{
    emit SignalSOCKET(SOCKET);
}

void AdminLogsSystem::SlotProcesos(int Procesos)
{
    emit SignalProcesos(Procesos);
}

void AdminLogsSystem::SlotStatusWIFI(bool StatusWIFI)
{
    emit SignalStatusWIFI(StatusWIFI);
}

void AdminLogsSystem::SlotEspacioDisco(QString EspacioDisco)
{
    emit SignalEspacioDisco(EspacioDisco);
}

void AdminLogsSystem::initHilo(int accion)
{
    emit operate(accion);
}

void AdminLogsSystem::handleResults(const QString &result)
{

}


