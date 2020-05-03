/****************************************************************************
** Meta object code from reading C++ file 'racimoaire.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "racimoaire.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'racimoaire.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RACIMOAIRE_t {
    QByteArrayData data[25];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RACIMOAIRE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RACIMOAIRE_t qt_meta_stringdata_RACIMOAIRE = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RACIMOAIRE"
QT_MOC_LITERAL(1, 11, 23), // "InitMuestraDataPromedio"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 10), // "newDataOPC"
QT_MOC_LITERAL(4, 47, 3), // "PM1"
QT_MOC_LITERAL(5, 51, 5), // "PM2_5"
QT_MOC_LITERAL(6, 57, 4), // "PM10"
QT_MOC_LITERAL(7, 62, 10), // "newDataGPS"
QT_MOC_LITERAL(8, 73, 8), // "latitude"
QT_MOC_LITERAL(9, 82, 9), // "longitude"
QT_MOC_LITERAL(10, 92, 15), // "latitudeDegrees"
QT_MOC_LITERAL(11, 108, 16), // "longitudeDegrees"
QT_MOC_LITERAL(12, 125, 7), // "int32_t"
QT_MOC_LITERAL(13, 133, 13), // "latitude_fixe"
QT_MOC_LITERAL(14, 147, 15), // "longitude_fixed"
QT_MOC_LITERAL(15, 163, 10), // "newDataPMS"
QT_MOC_LITERAL(16, 174, 8), // "uint16_t"
QT_MOC_LITERAL(17, 183, 11), // "initDataPMS"
QT_MOC_LITERAL(18, 195, 6), // "DataOk"
QT_MOC_LITERAL(19, 202, 27), // "DataRacimoAire::DATARACIMO*"
QT_MOC_LITERAL(20, 230, 5), // "_Data"
QT_MOC_LITERAL(21, 236, 28), // "DataRacimoAire::Struct_MOPC*"
QT_MOC_LITERAL(22, 265, 5), // "_MOPC"
QT_MOC_LITERAL(23, 271, 28), // "DataRacimoAire::Struct_MPMS*"
QT_MOC_LITERAL(24, 300, 5) // "_MPMS"

    },
    "RACIMOAIRE\0InitMuestraDataPromedio\0\0"
    "newDataOPC\0PM1\0PM2_5\0PM10\0newDataGPS\0"
    "latitude\0longitude\0latitudeDegrees\0"
    "longitudeDegrees\0int32_t\0latitude_fixe\0"
    "longitude_fixed\0newDataPMS\0uint16_t\0"
    "initDataPMS\0DataOk\0DataRacimoAire::DATARACIMO*\0"
    "_Data\0DataRacimoAire::Struct_MOPC*\0"
    "_MOPC\0DataRacimoAire::Struct_MPMS*\0"
    "_MPMS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RACIMOAIRE[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    3,   45,    2, 0x08 /* Private */,
       7,    6,   52,    2, 0x08 /* Private */,
      15,    3,   65,    2, 0x08 /* Private */,
      17,    0,   72,    2, 0x08 /* Private */,
      18,    3,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    4,    5,    6,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, 0x80000000 | 12, 0x80000000 | 12,    8,    9,   10,   11,   13,   14,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16, 0x80000000 | 16,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21, 0x80000000 | 23,   20,   22,   24,

       0        // eod
};

void RACIMOAIRE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RACIMOAIRE *_t = static_cast<RACIMOAIRE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InitMuestraDataPromedio(); break;
        case 1: _t->newDataOPC((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->newDataGPS((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< int32_t(*)>(_a[5])),(*reinterpret_cast< int32_t(*)>(_a[6]))); break;
        case 3: _t->newDataPMS((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< uint16_t(*)>(_a[3]))); break;
        case 4: _t->initDataPMS(); break;
        case 5: _t->DataOk((*reinterpret_cast< DataRacimoAire::DATARACIMO*(*)>(_a[1])),(*reinterpret_cast< DataRacimoAire::Struct_MOPC*(*)>(_a[2])),(*reinterpret_cast< DataRacimoAire::Struct_MPMS*(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject RACIMOAIRE::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RACIMOAIRE.data,
      qt_meta_data_RACIMOAIRE,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RACIMOAIRE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RACIMOAIRE::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RACIMOAIRE.stringdata0))
        return static_cast<void*>(const_cast< RACIMOAIRE*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RACIMOAIRE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
