#include "datajson2.h"

DataJson2::DataJson2(const QString &addrConfigJson, const QString &addrSabeData)
{
   setAddrKeysSabeData(addrSabeData + "KEY_BOX/key_box");
   setAddrSabeData(addrSabeData + "SAFE_BOX/");
   setAddrConfigJson(addrConfigJson);
   SetJson();
}

void DataJson2::SetJson()
{
   QFile file("/home/pi/RACIMOAIRE/Configuracion/JsonBase.json");
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       qDebug() << "Error al abrir archivo de configuracion de Json";
       return;
   }
   QTextStream FileText(&file);
   QString in =FileText.readAll();
   QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());
   // check valides del documento
   if(!doc.isNull())
   {
       if(doc.isObject())
       {
           Estacion_Json = doc.object();
       }
       else
       {
           qDebug() << "Documento JsonCofig no es un QJsonObjeto" << endl;
       }
   }
   else
   {
       qDebug() << "Json Invalido...\n" << in << endl;
   }

}

void DataJson2::SetDato(QString Key, int Value)
{
   OtherData.insert("id_parametro",Key);
   OtherData.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
   OtherData.insert("valor",Value);
   Array.insert(0,OtherData);
   Estacion_Json.insert("mediciones",Array);


}

void DataJson2::SetDato(QString Key, float Value)
{
   OtherData.insert("id_parametro",Key);
   OtherData.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
   OtherData.insert("valor",Value);
   Array.insert(0,OtherData);
   Estacion_Json.insert("mediciones",Array);

}
void DataJson2::SetDato(QString Key, double Value)
{
   OtherData.insert("id_parametro",Key);
   OtherData.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
   OtherData.insert("valor",Value);
   Array.insert(0,OtherData);
   Estacion_Json.insert("mediciones",Array);

}

void DataJson2::SetDato(QString Key, QString Value)
{
    OtherData.insert("id_parametro",Key);
    OtherData.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
    OtherData.insert("valor",Value);
    Array.insert(0,OtherData);
    Estacion_Json.insert("mediciones",Array);
}

void DataJson2::SetDato(DataJson2::VariablesBase Key, int Value)
{
   switch (Key) {
   case Humedad:
   {
       Humedad_Json.insert("id_parametro","h");
       Humedad_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       Humedad_Json.insert("valor",Value);
       Array.insert(0,Humedad_Json);
       break;
   }
   case Presion:
   {
       Presion_Json.insert("id_parametro","p");
       Presion_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       Presion_Json.insert("valor",Value);
       Array.insert(0,Presion_Json);
       break;
   }
   case Temperatura:
   {
       Temperatura_Json.insert("id_parametro","t");
       Temperatura_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       Temperatura_Json.insert("valor",Value);
       Array.insert(0,Temperatura_Json);

       break;
   }
   case PM10:
   {
       PM10_Json.insert("id_parametro","pm10");
       PM10_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       PM10_Json.insert("valor",Value);
       Array.insert(0,PM10_Json);

       break;
   }
   case PM2_5:
   {
       PM2_5_Json.insert("id_parametro","pm25");
       PM2_5_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       PM2_5_Json.insert("valor",Value);
       Array.insert(0,PM2_5_Json);

       break;
   }
   case PM1:
   {
       PM1_Json.insert("id_parametro","pm1");
       PM1_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       PM1_Json.insert("valor",Value);
       Array.insert(0,PM1_Json);

       break;
   }
   case PM10_A:
   {
       PM10_A_Json.insert("id_parametro","pm10_a");
       PM10_A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       PM10_A_Json.insert("valor",Value);
       Array.insert(0,PM10_A_Json);

       break;
   }
   case PM2_5_A:
   {
       PM2_5_A_Json.insert("id_parametro","pm25_a");
       PM2_5_A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       PM2_5_A_Json.insert("valor",Value);
       Array.insert(0,PM2_5_A_Json);

       break;
   }
   case PM1_A:
   {
       PM1_A_Json.insert("id_parametro","pm1_a");
       PM1_A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
       PM1_A_Json.insert("valor",Value);
       Array.insert(0,PM1_A_Json);

       break;
   }
   default:
       break;
   }
  // Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};
   Estacion_Json.insert("mediciones",Array);
}

void DataJson2::SetDato(DataJson2::VariablesBase Key, float Value)
{
    switch (Key) {
    case Humedad:
    {
        Humedad_Json.insert("id_parametro","h");
        Humedad_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Humedad_Json.insert("valor",Value);
        Array.insert(0,Humedad_Json);
        break;
    }
    case Presion:
    {
        Presion_Json.insert("id_parametro","p");
        Presion_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Presion_Json.insert("valor",Value);
        Array.insert(0,Presion_Json);
        break;
    }
    case Temperatura:
    {
        Temperatura_Json.insert("id_parametro","t");
        Temperatura_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        Temperatura_Json.insert("valor",Value);
        Array.insert(0,Temperatura_Json);

        break;
    }
    case PM10:
    {
        PM10_Json.insert("id_parametro","pm10");
        PM10_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10_Json.insert("valor",Value);
        Array.insert(0,PM10_Json);

        break;
    }
    case PM2_5:
    {
        PM2_5_Json.insert("id_parametro","pm25");
        PM2_5_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5_Json.insert("valor",Value);
        Array.insert(0,PM2_5_Json);

        break;
    }
    case PM1:
    {
        PM1_Json.insert("id_parametro","pm1");
        PM1_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM1_Json.insert("valor",Value);
        Array.insert(0,PM1_Json);

        break;
    }
    case PM10_A:
    {
        PM10_A_Json.insert("id_parametro","pm10_a");
        PM10_A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM10_A_Json.insert("valor",Value);
        Array.insert(0,PM10_A_Json);

        break;
    }
    case PM2_5_A:
    {
        PM2_5_A_Json.insert("id_parametro","pm25_a");
        PM2_5_A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM2_5_A_Json.insert("valor",Value);
        Array.insert(0,PM2_5_A_Json);

        break;
    }
    case PM1_A:
    {
        PM1_A_Json.insert("id_parametro","pm1_a");
        PM1_A_Json.insert("fecha_hora_med",QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z"));
        PM1_A_Json.insert("valor",Value);
        Array.insert(0,PM1_A_Json);

        break;
    }
    default:
        break;
    }
   // Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};
    Estacion_Json.insert("mediciones",Array);
}

void DataJson2::SetDato(DataJson2::ConstantesCabecera Key, QString Value)
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
   //Array= {Humedad_Json,Presion_Json,Temperatura_Json,PM10_Json,PM2_5_Json};
   //Estacion_Json.insert("mediciones",Array);
}

void DataJson2::ClearArray()
{
   while(!Array.isEmpty())Array.removeFirst();
   Estacion_Json.insert("mediciones",Array);

}

bool DataJson2::WriteJson()
{
   QString addrArchivo = QString("%1%2.json").arg(m_addrSabeData).arg(QDateTime::currentDateTime().toString(Qt::ISODate).replace(':','_').replace('-','_'));
   QFile file(addrArchivo);
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
      return false;

   QFile file_key_box(m_addrKeysSabeData);
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

bool DataJson2::readJson(QStringList *DataJsonString)
{
   DataJsonString->clear();
   QFile file_key_box(m_addrKeysSabeData);
   if (!file_key_box.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       qDebug() << "Error al abrir archivo de Keys Json";
       return false;
   }
   QTextStream keyJson(&file_key_box);
   QStringList keyJsonString = keyJson.readAll().split("^" , QString::SkipEmptyParts);

   //QString addrJson;
   for(int i=0; i<keyJsonString.length();i++)
   {
       //addrJson= QString("rm %1").arg(keyJsonString.operator [](i));
       QFile file(keyJsonString.operator [](i));
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           qDebug() << "Error al abrir archivo Json  " <<keyJsonString.operator [](i) ;

           //return false;

       }
       else
       {
           QTextStream ArchivoJson(&file);
           DataJsonString->append(ArchivoJson.readAll());
           file.close();
           //system(addrJson.toStdString().c_str());

       }
    }
   file_key_box.close();
   /*QString key_box = m_addrKeysSabeData;
   key_box = QString("rm %1").arg(key_box);
   system(key_box.toStdString().c_str());
*/
   return true;
}

void DataJson2::ClearJson()
{
    QFile file_key_box(m_addrKeysSabeData);
    if (!file_key_box.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error al abrir archivo de Keys Json";
        return;
    }
    QTextStream keyJson(&file_key_box);
    QStringList keyJsonString = keyJson.readAll().split("^" , QString::SkipEmptyParts);

    QString addrJson;
    for(int i=0; i<keyJsonString.length();i++)
    {
        addrJson= QString("rm %1").arg(keyJsonString.operator [](i));
        system(addrJson.toStdString().c_str());
    }
    file_key_box.close();
    QString key_box = m_addrKeysSabeData;
    key_box = QString("rm %1").arg(key_box);
    system(key_box.toStdString().c_str());

}

QString DataJson2::addrSabeData() const
{
   return m_addrSabeData;
}

void DataJson2::setAddrSabeData(const QString &addrSabeData)
{
   m_addrSabeData = addrSabeData;
}

QString DataJson2::addrConfigJson() const
{
   return m_addrConfigJson;
}

void DataJson2::setAddrConfigJson(const QString &addrConfigJson)
{
   m_addrConfigJson = addrConfigJson;
}

QString DataJson2::addrKeysSabeData() const
{
   return m_addrKeysSabeData;
}

void DataJson2::setAddrKeysSabeData(const QString &addrKeysSabeData)
{
   m_addrKeysSabeData = addrKeysSabeData;
}
