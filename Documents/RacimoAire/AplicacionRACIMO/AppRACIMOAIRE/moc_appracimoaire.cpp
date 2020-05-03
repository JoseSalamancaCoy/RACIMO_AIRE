/****************************************************************************
** Meta object code from reading C++ file 'appracimoaire.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "appracimoaire.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appracimoaire.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_appRacimoAire_t {
    QByteArrayData data[18];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_appRacimoAire_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_appRacimoAire_t qt_meta_stringdata_appRacimoAire = {
    {
QT_MOC_LITERAL(0, 0, 13), // "appRacimoAire"
QT_MOC_LITERAL(1, 14, 10), // "NewDataBME"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "newDataGPS"
QT_MOC_LITERAL(4, 37, 8), // "latitude"
QT_MOC_LITERAL(5, 46, 9), // "longitude"
QT_MOC_LITERAL(6, 56, 15), // "latitudeDegrees"
QT_MOC_LITERAL(7, 72, 16), // "longitudeDegrees"
QT_MOC_LITERAL(8, 89, 7), // "int32_t"
QT_MOC_LITERAL(9, 97, 13), // "latitude_fixe"
QT_MOC_LITERAL(10, 111, 15), // "longitude_fixed"
QT_MOC_LITERAL(11, 127, 6), // "DataOk"
QT_MOC_LITERAL(12, 134, 28), // "DataParticulado::DATARACIMO*"
QT_MOC_LITERAL(13, 163, 5), // "_Data"
QT_MOC_LITERAL(14, 169, 29), // "DataParticulado::Struct_MOPC*"
QT_MOC_LITERAL(15, 199, 5), // "_MOPC"
QT_MOC_LITERAL(16, 205, 29), // "DataParticulado::Struct_MPMS*"
QT_MOC_LITERAL(17, 235, 5) // "_MPMS"

    },
    "appRacimoAire\0NewDataBME\0\0newDataGPS\0"
    "latitude\0longitude\0latitudeDegrees\0"
    "longitudeDegrees\0int32_t\0latitude_fixe\0"
    "longitude_fixed\0DataOk\0"
    "DataParticulado::DATARACIMO*\0_Data\0"
    "DataParticulado::Struct_MOPC*\0_MOPC\0"
    "DataParticulado::Struct_MPMS*\0_MPMS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_appRacimoAire[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    6,   30,    2, 0x08 /* Private */,
      11,    3,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, 0x80000000 | 8, 0x80000000 | 8,    4,    5,    6,    7,    9,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14, 0x80000000 | 16,   13,   15,   17,

       0        // eod
};

void appRacimoAire::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        appRacimoAire *_t = static_cast<appRacimoAire *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewDataBME(); break;
        case 1: _t->newDataGPS((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5])),(*reinterpret_cast< int32_t(*)>(_a[6]))); break;
        case 2: _t->DataOk((*reinterpret_cast< DataParticulado::DATARACIMO*(*)>(_a[1])),(*reinterpret_cast< DataParticulado::Struct_MOPC*(*)>(_a[2])),(*reinterpret_cast< DataParticulado::Struct_MPMS*(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject appRacimoAire::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_appRacimoAire.data,
      qt_meta_data_appRacimoAire,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *appRacimoAire::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *appRacimoAire::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_appRacimoAire.stringdata0))
        return static_cast<void*>(const_cast< appRacimoAire*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int appRacimoAire::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
