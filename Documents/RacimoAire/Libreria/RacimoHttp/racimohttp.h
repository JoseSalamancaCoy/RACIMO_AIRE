#ifndef RACIMOHTTP_H
#define RACIMOHTTP_H

#include "racimohttp_global.h"
#include <QFile>
#include <QDateTime>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <stdio.h>
#include <curl/curl.h>
#include <QDebug>

class RACIMOHTTPSHARED_EXPORT RacimoHttp
{
public:
    void POSTHttp(char *charjson);
    void SetHora();

};

#endif // RACIMOHTTP_H
