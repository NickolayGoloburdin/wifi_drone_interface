/****************************************************************************
** Meta object code from reading C++ file 'sensors_handler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sensors_handler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensors_handler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_domain__SensorHandler_t {
    QByteArrayData data[5];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_domain__SensorHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_domain__SensorHandler_t qt_meta_stringdata_domain__SensorHandler = {
    {
QT_MOC_LITERAL(0, 0, 21), // "domain::SensorHandler"
QT_MOC_LITERAL(1, 22, 14), // "processMessage"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 17), // "mavlink_message_t"
QT_MOC_LITERAL(4, 56, 7) // "message"

    },
    "domain::SensorHandler\0processMessage\0"
    "\0mavlink_message_t\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_domain__SensorHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void domain::SensorHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SensorHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processMessage((*reinterpret_cast< const mavlink_message_t(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject domain::SensorHandler::staticMetaObject = { {
    &AbstractHandler::staticMetaObject,
    qt_meta_stringdata_domain__SensorHandler.data,
    qt_meta_data_domain__SensorHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *domain::SensorHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *domain::SensorHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_domain__SensorHandler.stringdata0))
        return static_cast<void*>(this);
    return AbstractHandler::qt_metacast(_clname);
}

int domain::SensorHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
