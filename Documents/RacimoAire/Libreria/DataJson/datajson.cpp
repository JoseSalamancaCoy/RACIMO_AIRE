#include "datajson.h"

DataJson::DataJson(QString _id_estacion,QString _nombre_estacion,QString _longitud,QString _latitud,QString _addData="/home/pi/RACIMOAIRE")
{
    addBase =_addData;
    SetDato(id_estacion,_id_estacion);
    SetDato(nombre_estacion,_nombre_estacion);
    SetDato(longitud,_longitud);
    SetDato(latitud,_latitud);

    SetDato(Humedad,0,false);
    SetDato(Presion,0,false);
    SetDato(Temperatura,0,false);
    SetDato(PM10,0,false);
    SetDato(PM2_5,0,false);
    SetDato(PM10PMS,0,false);
    SetDato(PM2_5PMS,0,false);
    Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};
    Estacion_Json.insert("mediciones",Array);

}

void DataJson::SetDato(Variables Key, int Value, bool RACIMO_TESTSENSORES=false)
{
    switch (Key) {
    case Humedad:
    {
        Humedad_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Humedad_Json.insert("valor",Value);
        break;
    }
    case Presion:
    {
        Presion_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Presion_Json.insert("valor",Value);
        break;
    }
    case Temperatura:
    {
        Temperatura_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Temperatura_Json.insert("valor",Value);
        break;
    }
    case PM10:
    {
        PM10_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10_Json.insert("valor",Value);
        break;
    }
    case PM2_5:
    {
        PM2_5_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5_Json.insert("valor",Value);
        break;
    }
    case PM10PMS:
    {
        PM10PMS_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMS_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMS:
    {
        PM2_5PMS_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMS_Json.insert("valor",Value);
        break;
    }
    //---------------------------------------Sensores2
    case PM10A:
    {
        PM10A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10A_Json.insert("valor",Value);
        break;
    }
    case PM2_5A:
    {
        PM2_5A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5A_Json.insert("valor",Value);
        break;
    }
    case PM10PMSA:
    {
        PM10PMSA_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMSA_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMSA:
    {
        PM2_5PMSA_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMSA_Json.insert("valor",Value);
        break;
    }
    //---------------------------------------Sensores3
    case PM10B:
    {
        PM10B_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10B_Json.insert("valor",Value);
        break;
    }
    case PM2_5B:
    {
        PM2_5B_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5B_Json.insert("valor",Value);
        break;
    }
    case PM10PMSB:
    {
        PM10PMSB_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMSB_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMSB:
    {
        PM2_5PMSB_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMSB_Json.insert("valor",Value);
        break;
    }
    //---------------------------------------Sensores4
    case PM10C:
    {
        PM10C_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10C_Json.insert("valor",Value);
        break;
    }
    case PM2_5C:
    {
        PM2_5C_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5C_Json.insert("valor",Value);
        break;
    }
    case PM10PMSC:
    {
        PM10PMSC_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMSC_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMSC:
    {
        PM2_5PMSC_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMSC_Json.insert("valor",Value);
        break;
    }
    //---------------------------------------Sensores5
    case PM10D:
    {
        PM10D_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10D_Json.insert("valor",Value);
        break;
    }
    case PM2_5D:
    {
        PM2_5D_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5D_Json.insert("valor",Value);
        break;
    }
    case PM10PMSD:
    {
        PM10PMSD_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMSD_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMSD:
    {
        PM2_5PMSD_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMSD_Json.insert("valor",Value);
        break;
    }
    default:
        break;
    }
    if(!RACIMO_TESTSENSORES) Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json,PM10PMS_Json,PM2_5PMS_Json};
    else Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json,PM10PMS_Json,PM2_5PMS_Json,
                                                                   PM10A_Json,PM2_5A_Json,PM10PMSA_Json,PM2_5PMSA_Json,
                                                                   PM10B_Json,PM2_5B_Json,PM10PMSB_Json,PM2_5PMSB_Json,
                                                                   PM10C_Json,PM2_5C_Json,PM10PMSC_Json,PM2_5PMSC_Json,
                                                                   PM10D_Json,PM2_5D_Json,PM10PMSD_Json,PM2_5PMSD_Json};

    Estacion_Json.insert("mediciones",Array);

}

void DataJson::SetDato(Variables Key, float Value,bool RACIMO_TESTSENSORES=false)
{
    switch (Key) {
    case Humedad:
    {
        Humedad_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Humedad_Json.insert("valor",Value);
        break;
    }
    case Presion:
    {
        Presion_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Presion_Json.insert("valor",Value);
        break;
    }
    case Temperatura:
    {
        Temperatura_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Temperatura_Json.insert("valor",Value);
        break;
    }
    case PM10:
    {
        PM10_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10_Json.insert("valor",Value);
        break;
    }
    case PM2_5:
    {
        PM2_5_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5_Json.insert("valor",Value);
        break;
    }
    case PM10PMS:
    {
        PM10PMS_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMS_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMS:
    {
        PM2_5PMS_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMS_Json.insert("valor",Value);
        break;
    }
   //---------------------------------------Sensores2
    case PM10A:
    {
        PM10A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10A_Json.insert("valor",Value);
        break;
    }
    case PM2_5A:
    {
        PM2_5A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5A_Json.insert("valor",Value);
        break;
    }
    case PM10PMSA:
    {
        PM10PMSA_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMSA_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMSA:
    {
        PM2_5PMSA_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMSA_Json.insert("valor",Value);
        break;
    }
    //---------------------------------------Sensores3
    case PM10B:
    {
        PM10B_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10B_Json.insert("valor",Value);
        break;
    }
    case PM2_5B:
    {
        PM2_5B_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5B_Json.insert("valor",Value);
        break;
    }
    case PM10PMSB:
    {
        PM10PMSB_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMSB_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMSB:
    {
        PM2_5PMSB_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMSB_Json.insert("valor",Value);
        break;
    }
    //---------------------------------------Sensores4
    case PM10C:
    {
        PM10C_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10C_Json.insert("valor",Value);
        break;
    }
    case PM2_5C:
    {
        PM2_5C_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5C_Json.insert("valor",Value);
        break;
    }
    case PM10PMSC:
    {
        PM10PMSC_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMSC_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMSC:
    {
        PM2_5PMSC_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMSC_Json.insert("valor",Value);
        break;
    }
    //---------------------------------------Sensores5
    case PM10D:
    {
        PM10D_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10D_Json.insert("valor",Value);
        break;
    }
    case PM2_5D:
    {
        PM2_5D_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5D_Json.insert("valor",Value);
        break;
    }
    case PM10PMSD:
    {
        PM10PMSD_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10PMSD_Json.insert("valor",Value);
        break;
    }
    case PM2_5PMSD:
    {
        PM2_5PMSD_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5PMSD_Json.insert("valor",Value);
        break;
    }
    default:
        break;
    }
    if(!RACIMO_TESTSENSORES) Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json,PM10PMS_Json,PM2_5PMS_Json};
    else Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json,PM10PMS_Json,PM2_5PMS_Json,
                                                                   PM10A_Json,PM2_5A_Json,PM10PMSA_Json,PM2_5PMSA_Json,
                                                                   PM10B_Json,PM2_5B_Json,PM10PMSB_Json,PM2_5PMSB_Json,
                                                                   PM10C_Json,PM2_5C_Json,PM10PMSC_Json,PM2_5PMSC_Json,
                                                                   PM10D_Json,PM2_5D_Json,PM10PMSD_Json,PM2_5PMSD_Json};

    Estacion_Json.insert("mediciones",Array);
}

void DataJson::SetDato(ConstantesCabecera Key, QString Value)
{
    switch (Key) {
    case id_estacion:       Estacion_Json.insert("id_estacion",Value);      break;
    case nombre_estacion:   Estacion_Json.insert("nombre_estacion",Value);  break;
    case clase:             Estacion_Json.insert("clase",Value);            break;
    case tipo:              Estacion_Json.insert("tipo",Value);             break;
    case descripcion:       Estacion_Json.insert("descripcion",Value);      break;
    case longitud:          Estacion_Json.insert("longitud",Value);         break;
    case latitud:           Estacion_Json.insert("latitud",Value);          break;
    default:
        break;
    }
}

bool DataJson::WriteJson()
{
    QString addrArchivo = QString("%1/SAFE_BOX/%2.json").arg(addBase).arg(QDateTime::currentDateTime().toString(Qt::ISODate).replace(':','_').replace('-','_'));
    QFile file(addrArchivo);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
       return false;

    QString key_box = QString("%1/KEY_BOX/key_box").arg(addBase);
    QFile file_key_box(key_box);
    if (!file_key_box.open(QIODevice::Append | QIODevice::Text))
    {   if(!file_key_box.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    }

   QTextStream ArchivoJson(&file);
   ArchivoJson << QString(QJsonDocument(Estacion_Json).toJson()) << "\n";


   QTextStream keyJson(&file_key_box);
   keyJson << addrArchivo << "^";
   file.close();
   file_key_box.close();
   return true;
}

bool DataJson::readJson(QStringList *DataJsonString)
{

    DataJsonString->clear();
    QString key_box = QString("%1/KEY_BOX/key_box").arg(addBase);
    QFile file_key_box(key_box);
    if (!file_key_box.open(QIODevice::ReadOnly | QIODevice::Text))
      return false;
    QTextStream keyJson(&file_key_box);
    QStringList keyJsonString = keyJson.readAll().split("^" , QString::SkipEmptyParts);

    QString addrJson;
    for(int i=0; i<keyJsonString.length();i++)
    {
        addrJson= QString("rm %1").arg(keyJsonString.operator [](i));
        QFile file(keyJsonString.operator [](i));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return false;
        QTextStream ArchivoJson(&file);
        DataJsonString->append(ArchivoJson.readAll());
        file.close();
        system(addrJson.toStdString().c_str());
    }

    file_key_box.close();
    key_box = QString("rm %1").arg(key_box);
    system(key_box.toStdString().c_str());

    return true;
}
