/****************************************************************************
** Meta object code from reading C++ file 'gps.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gps.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gps.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GPS_t {
    QByteArrayData data[14];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GPS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GPS_t qt_meta_stringdata_GPS = {
    {
QT_MOC_LITERAL(0, 0, 3), // "GPS"
QT_MOC_LITERAL(1, 4, 7), // "newData"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 8), // "latitude"
QT_MOC_LITERAL(4, 22, 9), // "longitude"
QT_MOC_LITERAL(5, 32, 15), // "latitudeDegrees"
QT_MOC_LITERAL(6, 48, 16), // "longitudeDegrees"
QT_MOC_LITERAL(7, 65, 7), // "int32_t"
QT_MOC_LITERAL(8, 73, 13), // "latitude_fixe"
QT_MOC_LITERAL(9, 87, 15), // "longitude_fixed"
QT_MOC_LITERAL(10, 103, 5), // "OnISR"
QT_MOC_LITERAL(11, 109, 4), // "gpio"
QT_MOC_LITERAL(12, 114, 5), // "level"
QT_MOC_LITERAL(13, 120, 7) // "timeout"

    },
    "GPS\0newData\0\0latitude\0longitude\0"
    "latitudeDegrees\0longitudeDegrees\0"
    "int32_t\0latitude_fixe\0longitude_fixed\0"
    "OnISR\0gpio\0level\0timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GPS[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    3,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, 0x80000000 | 7, 0x80000000 | 7,    3,    4,    5,    6,    8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::UInt,   11,   12,   13,

       0        // eod
};

void GPS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GPS *_t = static_cast<GPS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newData((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5])),(*reinterpret_cast< int32_t(*)>(_a[6]))); break;
        case 1: _t->OnISR((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GPS::*_t)(float , float , float , float , int32_t , int32_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GPS::newData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GPS::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GPS.data,
      qt_meta_data_GPS,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GPS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GPS::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GPS.stringdata0))
        return static_cast<void*>(const_cast< GPS*>(this));
    return QObject::qt_metacast(_clname);
}

int GPS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GPS::newData(float _t1, float _t2, float _t3, float _t4, int32_t _t5, int32_t _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
