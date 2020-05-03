/****************************************************************************
** Meta object code from reading C++ file 'pms.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pms.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pms.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PMS_t {
    QByteArrayData data[9];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PMS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PMS_t qt_meta_stringdata_PMS = {
    {
QT_MOC_LITERAL(0, 0, 3), // "PMS"
QT_MOC_LITERAL(1, 4, 7), // "newData"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 8), // "uint16_t"
QT_MOC_LITERAL(4, 22, 6), // "PM_1_0"
QT_MOC_LITERAL(5, 29, 6), // "PM_2_5"
QT_MOC_LITERAL(6, 36, 5), // "PM_10"
QT_MOC_LITERAL(7, 42, 12), // "InitMuestras"
QT_MOC_LITERAL(8, 55, 14) // "timelecturaPMS"

    },
    "PMS\0newData\0\0uint16_t\0PM_1_0\0PM_2_5\0"
    "PM_10\0InitMuestras\0timelecturaPMS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PMS[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       7,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void PMS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PMS *_t = static_cast<PMS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newData((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< uint16_t(*)>(_a[3]))); break;
        case 1: _t->InitMuestras(); break;
        case 2: _t->timelecturaPMS(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PMS::*_t)(uint16_t , uint16_t , uint16_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PMS::newData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PMS::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PMS::InitMuestras)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject PMS::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PMS.data,
      qt_meta_data_PMS,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PMS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PMS::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PMS.stringdata0))
        return static_cast<void*>(const_cast< PMS*>(this));
    return QObject::qt_metacast(_clname);
}

int PMS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PMS::newData(uint16_t _t1, uint16_t _t2, uint16_t _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PMS::InitMuestras()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
