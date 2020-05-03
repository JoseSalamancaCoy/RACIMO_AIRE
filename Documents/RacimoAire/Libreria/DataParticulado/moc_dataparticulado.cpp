/****************************************************************************
** Meta object code from reading C++ file 'dataparticulado.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dataparticulado.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataparticulado.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataParticulado_t {
    QByteArrayData data[14];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataParticulado_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataParticulado_t qt_meta_stringdata_DataParticulado = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DataParticulado"
QT_MOC_LITERAL(1, 16, 6), // "DataOk"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "DataOkPMS"
QT_MOC_LITERAL(4, 34, 9), // "DataOkOPC"
QT_MOC_LITERAL(5, 44, 23), // "InitMuestraDataPromedio"
QT_MOC_LITERAL(6, 68, 17), // "CheckfirstdataPMS"
QT_MOC_LITERAL(7, 86, 10), // "newDataOPC"
QT_MOC_LITERAL(8, 97, 3), // "PM1"
QT_MOC_LITERAL(9, 101, 5), // "PM2_5"
QT_MOC_LITERAL(10, 107, 4), // "PM10"
QT_MOC_LITERAL(11, 112, 10), // "newDataPMS"
QT_MOC_LITERAL(12, 123, 8), // "uint16_t"
QT_MOC_LITERAL(13, 132, 11) // "initDataPMS"

    },
    "DataParticulado\0DataOk\0\0DataOkPMS\0"
    "DataOkOPC\0InitMuestraDataPromedio\0"
    "CheckfirstdataPMS\0newDataOPC\0PM1\0PM2_5\0"
    "PM10\0newDataPMS\0uint16_t\0initDataPMS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataParticulado[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    3,   55,    2, 0x06 /* Public */,
       4,    3,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   69,    2, 0x08 /* Private */,
       6,    0,   70,    2, 0x08 /* Private */,
       7,    3,   71,    2, 0x08 /* Private */,
      11,    3,   78,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 12,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void DataParticulado::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataParticulado *_t = static_cast<DataParticulado *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataOk(); break;
        case 1: _t->DataOkPMS((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->DataOkOPC((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 3: _t->InitMuestraDataPromedio(); break;
        case 4: _t->CheckfirstdataPMS(); break;
        case 5: _t->newDataOPC((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 6: _t->newDataPMS((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< uint16_t(*)>(_a[3]))); break;
        case 7: _t->initDataPMS(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataParticulado::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataParticulado::DataOk)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DataParticulado::*_t)(float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataParticulado::DataOkPMS)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DataParticulado::*_t)(float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataParticulado::DataOkOPC)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DataParticulado::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataParticulado.data,
      qt_meta_data_DataParticulado,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataParticulado::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataParticulado::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataParticulado.stringdata0))
        return static_cast<void*>(const_cast< DataParticulado*>(this));
    return QObject::qt_metacast(_clname);
}

int DataParticulado::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void DataParticulado::DataOk()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DataParticulado::DataOkPMS(float _t1, float _t2, float _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataParticulado::DataOkOPC(float _t1, float _t2, float _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
