/****************************************************************************
** Meta object code from reading C++ file 'racimoaire2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "racimoaire2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'racimoaire2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RacimoAire2_t {
    QByteArrayData data[24];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RacimoAire2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RacimoAire2_t qt_meta_stringdata_RacimoAire2 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RacimoAire2"
QT_MOC_LITERAL(1, 12, 10), // "NewDataBME"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "newDataGPS"
QT_MOC_LITERAL(4, 35, 10), // "newDataOPC"
QT_MOC_LITERAL(5, 46, 3), // "PM1"
QT_MOC_LITERAL(6, 50, 5), // "PM2_5"
QT_MOC_LITERAL(7, 56, 4), // "PM10"
QT_MOC_LITERAL(8, 61, 10), // "newDataPMS"
QT_MOC_LITERAL(9, 72, 8), // "uint16_t"
QT_MOC_LITERAL(10, 81, 11), // "initDataPMS"
QT_MOC_LITERAL(11, 93, 8), // "DataLogs"
QT_MOC_LITERAL(12, 102, 15), // "SlotTemperatura"
QT_MOC_LITERAL(13, 118, 11), // "temperatura"
QT_MOC_LITERAL(14, 130, 7), // "SlotRAM"
QT_MOC_LITERAL(15, 138, 3), // "RAM"
QT_MOC_LITERAL(16, 142, 10), // "SlotSOCKET"
QT_MOC_LITERAL(17, 153, 6), // "SOCKET"
QT_MOC_LITERAL(18, 160, 12), // "SlotProcesos"
QT_MOC_LITERAL(19, 173, 8), // "Procesos"
QT_MOC_LITERAL(20, 182, 14), // "SlotStatusWIFI"
QT_MOC_LITERAL(21, 197, 10), // "StatusWIFI"
QT_MOC_LITERAL(22, 208, 16), // "SlotEspacioDisco"
QT_MOC_LITERAL(23, 225, 12) // "EspacioDisco"

    },
    "RacimoAire2\0NewDataBME\0\0newDataGPS\0"
    "newDataOPC\0PM1\0PM2_5\0PM10\0newDataPMS\0"
    "uint16_t\0initDataPMS\0DataLogs\0"
    "SlotTemperatura\0temperatura\0SlotRAM\0"
    "RAM\0SlotSOCKET\0SOCKET\0SlotProcesos\0"
    "Procesos\0SlotStatusWIFI\0StatusWIFI\0"
    "SlotEspacioDisco\0EspacioDisco"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RacimoAire2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    3,   76,    2, 0x08 /* Private */,
       8,    3,   83,    2, 0x08 /* Private */,
      10,    0,   90,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      14,    1,   95,    2, 0x08 /* Private */,
      16,    1,   98,    2, 0x08 /* Private */,
      18,    1,  101,    2, 0x08 /* Private */,
      20,    1,  104,    2, 0x08 /* Private */,
      22,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   13,
    QMetaType::Void, QMetaType::Float,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void RacimoAire2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RacimoAire2 *_t = static_cast<RacimoAire2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewDataBME(); break;
        case 1: _t->newDataGPS(); break;
        case 2: _t->newDataOPC((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 3: _t->newDataPMS((*reinterpret_cast< uint16_t(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2])),(*reinterpret_cast< uint16_t(*)>(_a[3]))); break;
        case 4: _t->initDataPMS(); break;
        case 5: _t->DataLogs(); break;
        case 6: _t->SlotTemperatura((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->SlotRAM((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: _t->SlotSOCKET((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->SlotProcesos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->SlotStatusWIFI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->SlotEspacioDisco((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RacimoAire2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RacimoAire2.data,
      qt_meta_data_RacimoAire2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RacimoAire2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RacimoAire2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RacimoAire2.stringdata0))
        return static_cast<void*>(const_cast< RacimoAire2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RacimoAire2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
