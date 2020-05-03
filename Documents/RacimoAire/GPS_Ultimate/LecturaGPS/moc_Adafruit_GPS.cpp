/****************************************************************************
** Meta object code from reading C++ file 'Adafruit_GPS.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Adafruit_GPS.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Adafruit_GPS.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Adafruit_GPS_t {
    QByteArrayData data[18];
    char stringdata[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Adafruit_GPS_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Adafruit_GPS_t qt_meta_stringdata_Adafruit_GPS = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 7),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 7),
QT_MOC_LITERAL(4, 30, 4),
QT_MOC_LITERAL(5, 35, 6),
QT_MOC_LITERAL(6, 42, 7),
QT_MOC_LITERAL(7, 50, 4),
QT_MOC_LITERAL(8, 55, 5),
QT_MOC_LITERAL(9, 61, 3),
QT_MOC_LITERAL(10, 65, 8),
QT_MOC_LITERAL(11, 74, 12),
QT_MOC_LITERAL(12, 87, 8),
QT_MOC_LITERAL(13, 96, 9),
QT_MOC_LITERAL(14, 106, 5),
QT_MOC_LITERAL(15, 112, 4),
QT_MOC_LITERAL(16, 117, 5),
QT_MOC_LITERAL(17, 123, 7)
    },
    "Adafruit_GPS\0newData\0\0uint8_t\0hour\0"
    "minute\0seconds\0year\0month\0day\0uint16_t\0"
    "milliseconds\0latitude\0longitude\0OnISR\0"
    "gpio\0level\0timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Adafruit_GPS[] = {

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
       1,    9,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    3,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 10, QMetaType::Float, QMetaType::Float,    4,    5,    6,    7,    8,    9,   11,   12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::UInt,   15,   16,   17,

       0        // eod
};

void Adafruit_GPS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Adafruit_GPS *_t = static_cast<Adafruit_GPS *>(_o);
        switch (_id) {
        case 0: _t->newData((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2])),(*reinterpret_cast< uint8_t(*)>(_a[3])),(*reinterpret_cast< uint8_t(*)>(_a[4])),(*reinterpret_cast< uint8_t(*)>(_a[5])),(*reinterpret_cast< uint8_t(*)>(_a[6])),(*reinterpret_cast< uint16_t(*)>(_a[7])),(*reinterpret_cast< float(*)>(_a[8])),(*reinterpret_cast< float(*)>(_a[9]))); break;
        case 1: _t->OnISR((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Adafruit_GPS::*_t)(uint8_t , uint8_t , uint8_t , uint8_t , uint8_t , uint8_t , uint16_t , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Adafruit_GPS::newData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Adafruit_GPS::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Adafruit_GPS.data,
      qt_meta_data_Adafruit_GPS,  qt_static_metacall, 0, 0}
};


const QMetaObject *Adafruit_GPS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Adafruit_GPS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Adafruit_GPS.stringdata))
        return static_cast<void*>(const_cast< Adafruit_GPS*>(this));
    return QObject::qt_metacast(_clname);
}

int Adafruit_GPS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Adafruit_GPS::newData(uint8_t _t1, uint8_t _t2, uint8_t _t3, uint8_t _t4, uint8_t _t5, uint8_t _t6, uint16_t _t7, float _t8, float _t9)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
