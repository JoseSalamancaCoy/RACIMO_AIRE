#ifndef DATAJSON_H
#define DATAJSON_H

#include "datajson_global.h"

#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class DATAJSONSHARED_EXPORT DataJson
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
        {"id_parametro", "pm25"},
        {"valor", 50}
    };
    QJsonObject PM10PMS_Json = {
        {"id_parametro", "pm10PMS"},
        {"valor", 50}
    };
    QJsonObject PM2_5PMS_Json = {
        {"id_parametro", "pm25PMS"},
        {"valor", 50}
    };
    //--------------------Sensor2
    QJsonObject PM10A_Json = {
        {"id_parametro", "pm10A"},
        {"valor", 50}
    };
    QJsonObject PM2_5A_Json = {
        {"id_parametro", "pm25A"},
        {"valor", 50}
    };
    QJsonObject PM10PMSA_Json = {
        {"id_parametro", "pm10PMSA"},
        {"valor", 50}
    };
    QJsonObject PM2_5PMSA_Json = {
        {"id_parametro", "pm25PMSA"},
        {"valor", 50}
    };
    //--------------------Sensor3
    QJsonObject PM10B_Json = {
        {"id_parametro", "pm10B"},
        {"valor", 50}
    };
    QJsonObject PM2_5B_Json = {
        {"id_parametro", "pm25B"},
        {"valor", 50}
    };
    QJsonObject PM10PMSB_Json = {
        {"id_parametro", "pm10PMSB"},
        {"valor", 50}
    };
    QJsonObject PM2_5PMSB_Json = {
        {"id_parametro", "pm25PMSB"},
        {"valor", 50}
    };
    //--------------------Sensor4
    QJsonObject PM10C_Json = {
        {"id_parametro", "pm10C"},
        {"valor", 50}
    };
    QJsonObject PM2_5C_Json = {
        {"id_parametro", "pm25C"},
        {"valor", 50}
    };
    QJsonObject PM10PMSC_Json = {
        {"id_parametro", "pm10PMSC"},
        {"valor", 50}
    };
    QJsonObject PM2_5PMSC_Json = {
        {"id_parametro", "pm25PMSC"},
        {"valor", 50}
    };
    //--------------------Sensor5
    QJsonObject PM10D_Json = {
        {"id_parametro", "pm10D"},
        {"valor", 50}
    };
    QJsonObject PM2_5D_Json = {
        {"id_parametro", "pm25D"},
        {"valor", 50}
    };
    QJsonObject PM10PMSD_Json = {
        {"id_parametro", "pm10PMSD"},
        {"valor", 50}
    };
    QJsonObject PM2_5PMSD_Json = {
        {"id_parametro", "pm25PMSD"},
        {"valor", 50}
    };

    QJsonArray Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json,PM10PMS_Json,PM2_5PMS_Json};

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

    enum Variables{ Humedad, Presion, Temperatura, PM10, PM2_5,PM10PMS, PM2_5PMS,
                                                   PM10A, PM2_5A,PM10PMSA, PM2_5PMSA,
                                                   PM10B, PM2_5B,PM10PMSB, PM2_5PMSB,
                                                   PM10C, PM2_5C,PM10PMSC, PM2_5PMSC,
                                                   PM10D, PM2_5D,PM10PMSD, PM2_5PMSD};
    enum ConstantesCabecera{ id_estacion, nombre_estacion, clase, tipo, descripcion, longitud,latitud};
    void SetDato(Variables Key,int Value,bool RACIMO_TESTSENSORES);
    void SetDato(Variables Key,float Value,bool RACIMO_TESTSENSORES);
    void SetDato(ConstantesCabecera Key,QString Value);
    bool WriteJson();
    bool readJson(QStringList *DataJsonString);

    QString addBase;

};

#endif // DATAJSON_H
