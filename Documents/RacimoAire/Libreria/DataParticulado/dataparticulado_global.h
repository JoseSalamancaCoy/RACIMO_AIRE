#ifndef DATAPARTICULADO_GLOBAL_H
#define DATAPARTICULADO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DATAPARTICULADO_LIBRARY)
#  define DATAPARTICULADOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DATAPARTICULADOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAPARTICULADO_GLOBAL_H
