#include "racimohttp.h"


void RacimoHttp:: POSTHttp(char *charjson)
{
    CURL *hnd = curl_easy_init();
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(hnd, CURLOPT_URL, "http://racimo.mpsig.com:3000/racimohub/v013dev/datasets");
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Postman-Token: d75df676-a5e1-448a-8b70-177609f83454");
    headers = curl_slist_append(headers, "Cache-Control: no-cache");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, charjson ); //Envio

    CURLcode ret = curl_easy_perform(hnd);
}

void RacimoHttp::SetHora()
{
    system("GetHttpCurl >/home/pi/RACIMOAIRE/DataIntercambio/FechaHora.json");
    QFile ArchivoFechaHora("/home/pi/RACIMOAIRE/DataIntercambio/FechaHora.json");
    if(!ArchivoFechaHora.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(QString(ArchivoFechaHora.readAll()).toUtf8());
    // check validity of the document
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << QString(ArchivoFechaHora.readAll()) << endl;
    }
    QDateTime DateTime = QDateTime::fromString(obj.value("fechahora").toString(),Qt::DateFormat::ISODate);
    QString StringFechaHora =DateTime.toLocalTime().toString(Qt::DateFormat::ISODate).replace('T',' ');
    char SetHora[38];
    sprintf(SetHora,"sudo date --set \"%s\"",StringFechaHora.toStdString().c_str());
    qDebug() <<"SetHora en "<<StringFechaHora;
    system(SetHora);
}
