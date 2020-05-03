#ifndef RACIMOHTTP_H
#define RACIMOHTTP_H
#include <stdio.h>
#include <curl/curl.h>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class RacimoHttp
{
public:
    void POSTHttp(char *charjson);
    void SetHora();

};

#endif // RACIMOHTTP_H
