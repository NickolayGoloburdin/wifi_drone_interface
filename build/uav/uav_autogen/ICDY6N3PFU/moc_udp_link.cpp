/****************************************************************************
** Meta object code from reading C++ file 'udp_link.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "links/udp_link.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udp_link.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_domain__UdpLink_t {
    QByteArrayData data[17];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_domain__UdpLink_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_domain__UdpLink_t qt_meta_stringdata_domain__UdpLink = {
    {
QT_MOC_LITERAL(0, 0, 15), // "domain::UdpLink"
QT_MOC_LITERAL(1, 16, 13), // "rxPortChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "port"
QT_MOC_LITERAL(4, 36, 14), // "addressChanged"
QT_MOC_LITERAL(5, 51, 7), // "address"
QT_MOC_LITERAL(6, 59, 13), // "txPortChanged"
QT_MOC_LITERAL(7, 73, 2), // "up"
QT_MOC_LITERAL(8, 76, 4), // "down"
QT_MOC_LITERAL(9, 81, 8), // "sendData"
QT_MOC_LITERAL(10, 90, 4), // "data"
QT_MOC_LITERAL(11, 95, 9), // "setRxPort"
QT_MOC_LITERAL(12, 105, 10), // "setAddress"
QT_MOC_LITERAL(13, 116, 9), // "setTxPort"
QT_MOC_LITERAL(14, 126, 20), // "readPendingDatagrams"
QT_MOC_LITERAL(15, 147, 6), // "rxPort"
QT_MOC_LITERAL(16, 154, 6) // "txPort"

    },
    "domain::UdpLink\0rxPortChanged\0\0port\0"
    "addressChanged\0address\0txPortChanged\0"
    "up\0down\0sendData\0data\0setRxPort\0"
    "setAddress\0setTxPort\0readPendingDatagrams\0"
    "rxPort\0txPort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_domain__UdpLink[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       3,   88, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   73,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x0a /* Public */,
      11,    1,   78,    2, 0x0a /* Public */,
      12,    1,   81,    2, 0x0a /* Public */,
      13,    1,   84,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::Int, 0x00495103,
       5, QMetaType::QString, 0x00495103,
      16, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void domain::UdpLink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UdpLink *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rxPortChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addressChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->txPortChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->up(); break;
        case 4: _t->down(); break;
        case 5: _t->sendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->setRxPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setAddress((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setTxPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->readPendingDatagrams(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UdpLink::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UdpLink::rxPortChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UdpLink::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UdpLink::addressChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UdpLink::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UdpLink::txPortChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UdpLink *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->rxPort(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->address(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->txPort(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UdpLink *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRxPort(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setAddress(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setTxPort(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject domain::UdpLink::staticMetaObject = { {
    &AbstractLink::staticMetaObject,
    qt_meta_stringdata_domain__UdpLink.data,
    qt_meta_data_domain__UdpLink,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *domain::UdpLink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *domain::UdpLink::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_domain__UdpLink.stringdata0))
        return static_cast<void*>(this);
    return AbstractLink::qt_metacast(_clname);
}

int domain::UdpLink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractLink::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void domain::UdpLink::rxPortChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void domain::UdpLink::addressChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void domain::UdpLink::txPortChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
