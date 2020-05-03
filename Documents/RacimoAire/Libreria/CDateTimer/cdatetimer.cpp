#include "cdatetimer.h"



CDateTimer::CDateTimer(QString addrarchivo, QObject *parent) :
    QObject(parent)
{
    Timer = new QTimer;
    m_addrarchivo = addrarchivo;
}

void CDateTimer::StartTimer()
{
    qDebug() << "AJA";
    QFile file(m_addrarchivo);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Falla al abrir el archivo para leer la configuracion de tiempo";
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();
    QStringList List = line.split(" ", QString::SkipEmptyParts);
    QDateTime DateTimeMuestraAnt =  QDateTime::fromString(List[0],"yyyy-MM-ddTHH:mm:ss");

    qint64 SectInterrup;
    int64_t TimeAdd = (QString(List[1]).toInt()*3600) + (QString(List[2]).toInt()*60) +QString(List[3]).toInt();
    SectInterrup = DateTimeMuestraAnt.secsTo(QDateTime::currentDateTime());
    while(SectInterrup > 0)
    {
        SectInterrup = DateTimeMuestraAnt.secsTo(QDateTime::currentDateTime());
        DateTimeMuestraAnt = DateTimeMuestraAnt.addSecs(TimeAdd);
    }
    qDebug() <<"Segundo Faltantes para la siguiente muestra" << -SectInterrup;
    Timer->singleShot((SectInterrup*-1)*1000,this,SLOT(timer_timeout()));
    List[0] = DateTimeMuestraAnt.toString("yyyy-MM-ddTHH:mm:ss");
    file.close();
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Falla al abrir el archivo para escribir la nueva configuracion de tiempo";
        return;
    }
    QTextStream out(&file);
    out << List.join(' ');
    file.close();

}

QString CDateTimer::addrarchivo() const
{
    return m_addrarchivo;
}

void CDateTimer::setAddrarchivo(const QString &addrarchivo)
{
    m_addrarchivo = addrarchivo;
}


void CDateTimer::timer_timeout()
{
    emit timeout();
    qDebug() <<"Inicio de muestreo a las = "<< QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss");
}

