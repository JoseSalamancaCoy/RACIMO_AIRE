#ifndef OPCN2_GLOBAL_H
#define OPCN2_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OPCN2_LIBRARY)
#  define OPCN2SHARED_EXPORT Q_DECL_EXPORT
#else
#  define OPCN2SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // OPCN2_GLOBAL_H
