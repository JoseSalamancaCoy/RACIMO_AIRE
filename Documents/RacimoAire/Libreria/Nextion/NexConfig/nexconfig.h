#ifndef NEXCONFIG_H
#define NEXCONFIG_H

#include "nexconfig_global.h"
#include <QDebug>
#include <QString>

void dbSerialPrint(uint32_t a);
void dbSerialPrint(uint32_t *a);
void dbSerialPrintln(uint32_t a);
void dbSerialPrintln(uint32_t *a);

ulong millis();

void dbSerialPrint(QString a);
void dbSerialPrintln(QString a);



#endif // NEXCONFIG_H
