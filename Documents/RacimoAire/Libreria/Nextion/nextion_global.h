#ifndef NEXTION_GLOBAL_H
#define NEXTION_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NEXTION_LIBRARY)
#  define NEXTIONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NEXTIONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NEXTION_GLOBAL_H
