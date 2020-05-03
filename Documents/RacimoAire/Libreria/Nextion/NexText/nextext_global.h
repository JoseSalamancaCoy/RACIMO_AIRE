#ifndef NEXTEXT_GLOBAL_H
#define NEXTEXT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NEXTEXT_LIBRARY)
#  define NEXTEXTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NEXTEXTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NEXTEXT_GLOBAL_H
