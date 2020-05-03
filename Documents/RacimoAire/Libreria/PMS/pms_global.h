#ifndef PMS_GLOBAL_H
#define PMS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PMS_LIBRARY)
#  define PMSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PMSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PMS_GLOBAL_H
