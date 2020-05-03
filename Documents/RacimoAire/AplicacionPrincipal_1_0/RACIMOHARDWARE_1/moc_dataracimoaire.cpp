/****************************************************************************
** Meta object code from reading C++ file 'dataracimoaire.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dataracimoaire.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataracimoaire.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataRacimoAire_t {
    QByteArrayData data[17];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataRacimoAire_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataRacimoAire_t qt_meta_stringdata_DataRacimoAire = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DataRacimoAire"
QT_MOC_LITERAL(1, 15, 6), // "DataOk"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 27), // "DataRacimoAire::DATARACIMO*"
QT_MOC_LITERAL(4, 51, 5), // "_Data"
QT_MOC_LITERAL(5, 57, 28), // "DataRacimoAire::Struct_MOPC*"
QT_MOC_LITERAL(6, 86, 5), // "_MOPC"
QT_MOC_LITERAL(7, 92, 28), // "DataRacimoAire::Struct_MPMS*"
QT_MOC_LITERAL(8, 121, 5), // "_MPMS"
QT_MOC_LITERAL(9, 127, 23), // "InitMuestraDataPromedio"
QT_MOC_LITERAL(10, 151, 10), // "newDataOPC"
QT_MOC_LITERAL(11, 162, 3), // "PM1"
QT_MOC_LITERAL(12, 166, 5), // "PM2_5"
QT_MOC_LITERAL(13, 172, 4), // "PM10"
QT_MOC_LITERAL(14, 177, 10), // "newDataPMS"
QT_MOC_LITERAL(15, 188, 8), // "uint16_t"
QT_MOC_LITERAL(16, 197, 11) // "initDataPMS"

    },
    "DataRacimoAire\0DataOk\0\0"
    "DataRacimoAire::DATARACIMO*\0_Data\0"
    "DataRacimoAire::Struct_MOPC*\0_MOPC\0"
    "DataRacimoAire::Struct_MPMS*\0_MPMS\0"
    "InitMuestraDataPromedio\0newDataOPC\0"
    "PM1\0PM2_5\0PM10\0newDataPMS\0uint16_t\0"
    "initDataPMS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataRacimoAire[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   46,    2, 0x08 /* Private */,
      10,    3,   47,    2, 0x08 /* Private */,
      14,    3,   54,    2, 0x08 /* Private */,
      16,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15,   11,   12,   13,
    QMetaType::Void,

       0        // eod
};

void DataRacimoAire::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataRacimoAire *_t = static_cast<DataRacimoAire *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataOk((*reinterpret_cast< DataRacimoAire::DATARACIMO*(*)>(_a[1])),(*reinterpret_cast< DataRacimoAire::Struct_MOPC*(*)>(_a[2])),(*reinterpret_cast< DataRacimoAire::Struct_MPMS*(*)>(_a[3]))); break;
        case 1: _t->InitMuestraDataPromedio(); break;
        case 2: _t->newDataOPC((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 3: _t->newDataPMS((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< uint16_t(*)>(_a[3]))); break;
        case 4: _t->initDataPMS(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataRacimoAire::*_t)(DataRacimoAire::DATARACIMO * , DataRacimoAire::Struct_MOPC * , DataRacimoAire::Struct_MPMS * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataRacimoAire::DataOk)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DataRacimoAire::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataRacimoAire.data,
      qt_meta_data_DataRacimoAire,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataRacimoAire::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataRacimoAire::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataRacimoAire.stringdata0))
        return static_cast<void*>(const_cast< DataRacimoAire*>(this));
    return QObject::qt_metacast(_clname);
}

int DataRacimoAire::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DataRacimoAire::DataOk(DataRacimoAire::DATARACIMO * _t1, DataRacimoAire::Struct_MOPC * _t2, DataRacimoAire::Struct_MPMS * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
