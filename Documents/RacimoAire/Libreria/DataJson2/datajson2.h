#ifndef DATAJSON2_H
#define DATAJSON2_H

#include "datajson2_global.h"
#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class DATAJSON2SHARED_EXPORT DataJson2
{
public:

    DataJson2(const QString &addrConfigJson="/home/pi/RACIMOAIRE/Configuracion/JsonBase.json", const QString &addrSabeData = "/home/pi/RACIMOAIRE/");
    enum ConstantesCabecera{ id_estacion, nombre_estacion, clase, tipo, descripcion, longitud,latitud};
    enum VariablesBase{ Humedad, Presion, Temperatura, PM10, PM2_5, PM1, PM10_A, PM2_5_A, PM1_A};

    QJsonObject Humedad_Json;
    QJsonObject Presion_Json;
    QJsonObject Temperatura_Json;
    QJsonObject PM10_Json;
    QJsonObject PM2_5_Json;
    QJsonObject PM1_Json;
    QJsonObject PM10_A_Json;
    QJsonObject PM2_5_A_Json;
    QJsonObject PM1_A_Json;

    QJsonObject OtherData;
    QJsonArray Array;
    QJsonObject Estacion_Json;

    void SetJson();
    void SetDato(QString Key,int Value);
    void SetDato(QString Key,float Value);
    void SetDato(QString Key, double Value);
    void SetDato(QString Key,QString Value);
    void SetDato(VariablesBase Key,int Value);
    void SetDato(VariablesBase Key,float Value);
    void SetDato(ConstantesCabecera Key,QString Value);
    void ClearArray();
    bool WriteJson();
    bool readJson(QStringList *DataJsonString);
    void ClearJson();



    QString addrSabeData() const;
    void setAddrSabeData(const QString &addrSabeData);

    QString addrConfigJson() const;
    void setAddrConfigJson(const QString &addrConfigJson);

    QString addrKeysSabeData() const;
    void setAddrKeysSabeData(const QString &addrKeysSabeData);

private:

    QString m_addrSabeData;
    QString m_addrKeysSabeData;
    QString m_addrConfigJson;

};
#endif // DATAJSON2_H
