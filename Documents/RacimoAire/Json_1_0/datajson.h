#ifndef DATAJSON_H
#define DATAJSON_H

#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class DataJson
{
public:
    DataJson(QString _id_estacion,QString _nombre_estacion,QString _longitud,QString _latitud,QString _addData);
    QJsonObject Humedad_Json = {
        {"id_parametro", "h"},
        {"valor", 50}
    };
    QJsonObject Presion_Json = {
        {"id_parametro", "p"},
        {"valor", 50}
    };
    QJsonObject Temperatura_Json = {
        {"id_parametro", "t"},
        {"valor", 50}
    };
    QJsonObject PM10_Json = {
        {"id_parametro", "pm10"},
        {"valor", 50}
    };
    QJsonObject PM2_5_Json = {
        {"fecha_hora_med", "2018-08-21T17:33:00.000Z"},
        {"id_parametro", "pm25"},
        {"valor", 50}
    };
    QJsonArray Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};

    QJsonObject Estacion_Json={
    {"id_estacion", "uis-10"},
    {"nombre_estacion", "UIS-10"},
    {"clase", "Calidad de Aire"},
    {"tipo", "Profesional de bajo costo"},
    {"activa", true},
    {"id_red", 1},
    {"descripcion", "Estación de pruebas con José Luis"},
    {"longitud", "-73.12194"},
    {"latitud", "7.140129"},
    {"mediciones", Array}
    };

    enum Variables{ Humedad, Presion, Temperatura, PM10, PM2_5};
    enum ConstantesCabecera{ id_estacion, nombre_estacion, clase, tipo, descripcion, longitud,latitud};
    void SetDato(Variables Key,int Value);
    void SetDato(Variables Key,float Value);
    void SetDato(ConstantesCabecera Key,QString Value);
    bool WriteJson();
    bool readJson(QStringList *DataJsonString);

    QString addBase;

};

#endif // DATAJSON_H
