/****************************************************************************
** Meta object code from reading C++ file 'logssystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "logssystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logssystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LogsSystem_t {
    QByteArrayData data[18];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogsSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogsSystem_t qt_meta_stringdata_LogsSystem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LogsSystem"
QT_MOC_LITERAL(1, 11, 11), // "resultReady"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "result"
QT_MOC_LITERAL(4, 31, 17), // "SignalTemperatura"
QT_MOC_LITERAL(5, 49, 11), // "temperatura"
QT_MOC_LITERAL(6, 61, 9), // "SignalRAM"
QT_MOC_LITERAL(7, 71, 3), // "RAM"
QT_MOC_LITERAL(8, 75, 12), // "SignalSOCKET"
QT_MOC_LITERAL(9, 88, 6), // "SOCKET"
QT_MOC_LITERAL(10, 95, 14), // "SignalProcesos"
QT_MOC_LITERAL(11, 110, 8), // "Procesos"
QT_MOC_LITERAL(12, 119, 16), // "SignalStatusWIFI"
QT_MOC_LITERAL(13, 136, 10), // "StatusWIFI"
QT_MOC_LITERAL(14, 147, 18), // "SignalEspacioDisco"
QT_MOC_LITERAL(15, 166, 12), // "EspacioDisco"
QT_MOC_LITERAL(16, 179, 6), // "doWork"
QT_MOC_LITERAL(17, 186, 6) // "accion"

    },
    "LogsSystem\0resultReady\0\0result\0"
    "SignalTemperatura\0temperatura\0SignalRAM\0"
    "RAM\0SignalSOCKET\0SOCKET\0SignalProcesos\0"
    "Procesos\0SignalStatusWIFI\0StatusWIFI\0"
    "SignalEspacioDisco\0EspacioDisco\0doWork\0"
    "accion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogsSystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,
      10,    1,   66,    2, 0x06 /* Public */,
      12,    1,   69,    2, 0x06 /* Public */,
      14,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void LogsSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogsSystem *_t = static_cast<LogsSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resultReady((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->SignalTemperatura((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->SignalRAM((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->SignalSOCKET((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SignalProcesos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SignalStatusWIFI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->SignalEspacioDisco((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->doWork((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LogsSystem::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogsSystem::resultReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LogsSystem::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogsSystem::SignalTemperatura)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LogsSystem::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogsSystem::SignalRAM)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (LogsSystem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogsSystem::SignalSOCKET)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (LogsSystem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogsSystem::SignalProcesos)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (LogsSystem::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogsSystem::SignalStatusWIFI)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (LogsSystem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogsSystem::SignalEspacioDisco)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject LogsSystem::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_LogsSystem.data,
      qt_meta_data_LogsSystem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LogsSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogsSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LogsSystem.stringdata0))
        return static_cast<void*>(const_cast< LogsSystem*>(this));
    return QThread::qt_metacast(_clname);
}

int LogsSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LogsSystem::resultReady(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LogsSystem::SignalTemperatura(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LogsSystem::SignalRAM(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LogsSystem::SignalSOCKET(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LogsSystem::SignalProcesos(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LogsSystem::SignalStatusWIFI(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void LogsSystem::SignalEspacioDisco(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
