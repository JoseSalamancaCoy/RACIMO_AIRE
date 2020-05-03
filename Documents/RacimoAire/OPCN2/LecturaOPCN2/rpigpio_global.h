#ifndef RPIGPIO_GLOBAL_H
#define RPIGPIO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RPIGPIO_LIBRARY)
#  define RPIGPIOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RPIGPIOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RPIGPIO_GLOBAL_H
