#ifndef GPS_GLOBAL_H
#define GPS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GPS_LIBRARY)
#  define GPSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GPSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GPS_GLOBAL_H
