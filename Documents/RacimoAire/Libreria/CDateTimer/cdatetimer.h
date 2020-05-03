#ifndef CDATETIMER_H
#define CDATETIMER_H

#include "cdatetimer_global.h"

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
class QDateTime;

class CDATETIMERSHARED_EXPORT CDateTimer : public QObject
{
    Q_OBJECT
public:
    CDateTimer(QString addrarchivo = "/home/pi/RACIMOAIRE/Configuracion/TimeConfig.txt",QObject *parent=nullptr);
    void StartTimer();


    QString addrarchivo() const;
    void setAddrarchivo(const QString &addrarchivo);

signals:
    void timeout();

private:
    QTimer *Timer;
    QString m_addrarchivo;

private slots:
    void timer_timeout();
};
#endif // CDATETIMER_H
