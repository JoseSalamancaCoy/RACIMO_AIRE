#ifndef DATAJSON_GLOBAL_H
#define DATAJSON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DATAJSON_LIBRARY)
#  define DATAJSONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DATAJSONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAJSON_GLOBAL_H
