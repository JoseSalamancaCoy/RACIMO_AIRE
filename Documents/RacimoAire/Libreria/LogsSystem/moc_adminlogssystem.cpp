/****************************************************************************
** Meta object code from reading C++ file 'adminlogssystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "adminlogssystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminlogssystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdminLogsSystem_t {
    QByteArrayData data[24];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminLogsSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminLogsSystem_t qt_meta_stringdata_AdminLogsSystem = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AdminLogsSystem"
QT_MOC_LITERAL(1, 16, 7), // "operate"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "accion"
QT_MOC_LITERAL(4, 32, 17), // "SignalTemperatura"
QT_MOC_LITERAL(5, 50, 11), // "temperatura"
QT_MOC_LITERAL(6, 62, 9), // "SignalRAM"
QT_MOC_LITERAL(7, 72, 3), // "RAM"
QT_MOC_LITERAL(8, 76, 12), // "SignalSOCKET"
QT_MOC_LITERAL(9, 89, 6), // "SOCKET"
QT_MOC_LITERAL(10, 96, 14), // "SignalProcesos"
QT_MOC_LITERAL(11, 111, 8), // "Procesos"
QT_MOC_LITERAL(12, 120, 16), // "SignalStatusWIFI"
QT_MOC_LITERAL(13, 137, 10), // "StatusWIFI"
QT_MOC_LITERAL(14, 148, 18), // "SignalEspacioDisco"
QT_MOC_LITERAL(15, 167, 12), // "EspacioDisco"
QT_MOC_LITERAL(16, 180, 13), // "handleResults"
QT_MOC_LITERAL(17, 194, 6), // "result"
QT_MOC_LITERAL(18, 201, 15), // "SlotTemperatura"
QT_MOC_LITERAL(19, 217, 7), // "SlotRAM"
QT_MOC_LITERAL(20, 225, 10), // "SlotSOCKET"
QT_MOC_LITERAL(21, 236, 12), // "SlotProcesos"
QT_MOC_LITERAL(22, 249, 14), // "SlotStatusWIFI"
QT_MOC_LITERAL(23, 264, 16) // "SlotEspacioDisco"

    },
    "AdminLogsSystem\0operate\0\0accion\0"
    "SignalTemperatura\0temperatura\0SignalRAM\0"
    "RAM\0SignalSOCKET\0SOCKET\0SignalProcesos\0"
    "Procesos\0SignalStatusWIFI\0StatusWIFI\0"
    "SignalEspacioDisco\0EspacioDisco\0"
    "handleResults\0result\0SlotTemperatura\0"
    "SlotRAM\0SlotSOCKET\0SlotProcesos\0"
    "SlotStatusWIFI\0SlotEspacioDisco"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminLogsSystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       8,    1,   93,    2, 0x06 /* Public */,
      10,    1,   96,    2, 0x06 /* Public */,
      12,    1,   99,    2, 0x06 /* Public */,
      14,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,  105,    2, 0x0a /* Public */,
      18,    1,  108,    2, 0x0a /* Public */,
      19,    1,  111,    2, 0x0a /* Public */,
      20,    1,  114,    2, 0x0a /* Public */,
      21,    1,  117,    2, 0x0a /* Public */,
      22,    1,  120,    2, 0x0a /* Public */,
      23,    1,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QString,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void AdminLogsSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminLogsSystem *_t = static_cast<AdminLogsSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->operate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SignalTemperatura((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->SignalRAM((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SignalSOCKET((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SignalProcesos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SignalStatusWIFI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->SignalEspacioDisco((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->handleResults((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->SlotTemperatura((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->SlotRAM((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->SlotSOCKET((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->SlotProcesos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->SlotStatusWIFI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->SlotEspacioDisco((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AdminLogsSystem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdminLogsSystem::operate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AdminLogsSystem::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdminLogsSystem::SignalTemperatura)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AdminLogsSystem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdminLogsSystem::SignalRAM)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AdminLogsSystem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdminLogsSystem::SignalSOCKET)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AdminLogsSystem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdminLogsSystem::SignalProcesos)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (AdminLogsSystem::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdminLogsSystem::SignalStatusWIFI)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (AdminLogsSystem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AdminLogsSystem::SignalEspacioDisco)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject AdminLogsSystem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AdminLogsSystem.data,
      qt_meta_data_AdminLogsSystem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdminLogsSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminLogsSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdminLogsSystem.stringdata0))
        return static_cast<void*>(const_cast< AdminLogsSystem*>(this));
    return QObject::qt_metacast(_clname);
}

int AdminLogsSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void AdminLogsSystem::operate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AdminLogsSystem::SignalTemperatura(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AdminLogsSystem::SignalRAM(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AdminLogsSystem::SignalSOCKET(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AdminLogsSystem::SignalProcesos(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AdminLogsSystem::SignalStatusWIFI(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AdminLogsSystem::SignalEspacioDisco(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
