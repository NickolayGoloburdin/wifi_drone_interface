/****************************************************************************
** Meta object code from reading C++ file 'serial_link.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "links/serial_link.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_link.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_domain__SerialLink_t {
    QByteArrayData data[13];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_domain__SerialLink_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_domain__SerialLink_t qt_meta_stringdata_domain__SerialLink = {
    {
QT_MOC_LITERAL(0, 0, 18), // "domain::SerialLink"
QT_MOC_LITERAL(1, 19, 15), // "portNameChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "portName"
QT_MOC_LITERAL(4, 45, 15), // "baudRateChanged"
QT_MOC_LITERAL(5, 61, 8), // "baudRate"
QT_MOC_LITERAL(6, 70, 2), // "up"
QT_MOC_LITERAL(7, 73, 4), // "down"
QT_MOC_LITERAL(8, 78, 8), // "sendData"
QT_MOC_LITERAL(9, 87, 4), // "data"
QT_MOC_LITERAL(10, 92, 11), // "setPortName"
QT_MOC_LITERAL(11, 104, 11), // "setBaudRate"
QT_MOC_LITERAL(12, 116, 14) // "readSerialData"

    },
    "domain::SerialLink\0portNameChanged\0\0"
    "portName\0baudRateChanged\0baudRate\0up\0"
    "down\0sendData\0data\0setPortName\0"
    "setBaudRate\0readSerialData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_domain__SerialLink[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   72, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    1,   62,    2, 0x0a /* Public */,
      10,    1,   65,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      12,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void domain::SerialLink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialLink *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->portNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->baudRateChanged((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 2: _t->up(); break;
        case 3: _t->down(); break;
        case 4: _t->sendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->setPortName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setBaudRate((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 7: _t->readSerialData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialLink::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialLink::portNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialLink::*)(qint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialLink::baudRateChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SerialLink *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->portName(); break;
        case 1: *reinterpret_cast< qint32*>(_v) = _t->baudRate(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SerialLink *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPortName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setBaudRate(*reinterpret_cast< qint32*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject domain::SerialLink::staticMetaObject = { {
    &AbstractLink::staticMetaObject,
    qt_meta_stringdata_domain__SerialLink.data,
    qt_meta_data_domain__SerialLink,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *domain::SerialLink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *domain::SerialLink::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_domain__SerialLink.stringdata0))
        return static_cast<void*>(this);
    return AbstractLink::qt_metacast(_clname);
}

int domain::SerialLink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractLink::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void domain::SerialLink::portNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void domain::SerialLink::baudRateChanged(qint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
