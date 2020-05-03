#include "datajson.h"

DataJson::DataJson(QString _id_estacion,QString _nombre_estacion,QString _longitud,QString _latitud,QString _addData="/home/pi/RACIMOAIRE")
{
    addBase =_addData;
    SetDato(id_estacion,_id_estacion);
    SetDato(nombre_estacion,_nombre_estacion);
    SetDato(longitud,_longitud);
    SetDato(latitud,_latitud);

    SetDato(Humedad,0);
    SetDato(Presion,0);
    SetDato(Temperatura,0);
    SetDato(PM10,0);
    SetDato(PM2_5,0);
    Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};
    Estacion_Json.insert("mediciones",Array);

}

void DataJson::SetDato(Variables Key, int Value)
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
    default:
        break;
    }
    Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};
    Estacion_Json.insert("mediciones",Array);

}

void DataJson::SetDato(Variables Key, float Value)
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
    default:
        break;
    }
    Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};
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
    Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};
    Estacion_Json.insert("mediciones",Array);
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
