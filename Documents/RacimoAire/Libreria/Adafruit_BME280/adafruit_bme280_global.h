#ifndef ADAFRUIT_BME280_GLOBAL_H
#define ADAFRUIT_BME280_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ADAFRUIT_BME280_LIBRARY)
#  define ADAFRUIT_BME280SHARED_EXPORT Q_DECL_EXPORT
#else
#  define ADAFRUIT_BME280SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ADAFRUIT_BME280_GLOBAL_H
