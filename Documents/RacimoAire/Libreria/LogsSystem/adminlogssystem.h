#ifndef ADMINLOGSSYSTEM_H
#define ADMINLOGSSYSTEM_H

#include <QObject>
#include <logssystem.h>
#include <QThread>
class AdminLogsSystem : public QObject
{
    Q_OBJECT
     QThread logsSystemThread;
 public:
     AdminLogsSystem(QObject *parent=nullptr);
     ~AdminLogsSystem();
     void initHilo(int accion);
protected:
     public slots:
         void handleResults(const QString &result);
         void SlotTemperatura(float temperatura);
         void SlotRAM(QString RAM);
         void SlotSOCKET(int SOCKET);
         void SlotProcesos(int Procesos);
         void SlotStatusWIFI(bool StatusWIFI);
         void SlotEspacioDisco( QString EspacioDisco);
     signals:
         void operate(int accion);
         void SignalTemperatura(float temperatura);
         void SignalRAM(QString RAM);
         void SignalSOCKET(int SOCKET);
         void SignalProcesos(int Procesos);
         void SignalStatusWIFI(bool StatusWIFI);
         void SignalEspacioDisco( QString EspacioDisco);

     private:
         LogsSystem *logsSystem;


 };
#endif // ADMINLOGSSYSTEM_H
