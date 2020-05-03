#ifndef ADS1115_GLOBAL_H
#define ADS1115_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ADS1115_LIBRARY)
#  define ADS1115SHARED_EXPORT Q_DECL_EXPORT
#else
#  define ADS1115SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ADS1115_GLOBAL_H
