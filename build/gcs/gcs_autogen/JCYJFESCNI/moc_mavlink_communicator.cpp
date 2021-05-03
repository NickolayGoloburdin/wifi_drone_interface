/****************************************************************************
** Meta object code from reading C++ file 'mavlink_communicator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mavlink_communicator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mavlink_communicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_domain__MavLinkCommunicator_t {
    QByteArrayData data[21];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_domain__MavLinkCommunicator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_domain__MavLinkCommunicator_t qt_meta_stringdata_domain__MavLinkCommunicator = {
    {
QT_MOC_LITERAL(0, 0, 27), // "domain::MavLinkCommunicator"
QT_MOC_LITERAL(1, 28, 15), // "messageReceived"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 17), // "mavlink_message_t"
QT_MOC_LITERAL(4, 63, 7), // "message"
QT_MOC_LITERAL(5, 71, 7), // "addLink"
QT_MOC_LITERAL(6, 79, 13), // "AbstractLink*"
QT_MOC_LITERAL(7, 93, 4), // "link"
QT_MOC_LITERAL(8, 98, 7), // "uint8_t"
QT_MOC_LITERAL(9, 106, 7), // "channel"
QT_MOC_LITERAL(10, 114, 10), // "removeLink"
QT_MOC_LITERAL(11, 125, 11), // "setSystemId"
QT_MOC_LITERAL(12, 137, 8), // "systemId"
QT_MOC_LITERAL(13, 146, 14), // "setComponentId"
QT_MOC_LITERAL(14, 161, 11), // "componentId"
QT_MOC_LITERAL(15, 173, 11), // "sendMessage"
QT_MOC_LITERAL(16, 185, 18), // "mavlink_message_t&"
QT_MOC_LITERAL(17, 204, 29), // "sendMessageOnLastReceivedLink"
QT_MOC_LITERAL(18, 234, 21), // "sendMessageOnAllLinks"
QT_MOC_LITERAL(19, 256, 14), // "onDataReceived"
QT_MOC_LITERAL(20, 271, 4) // "data"

    },
    "domain::MavLinkCommunicator\0messageReceived\0"
    "\0mavlink_message_t\0message\0addLink\0"
    "AbstractLink*\0link\0uint8_t\0channel\0"
    "removeLink\0setSystemId\0systemId\0"
    "setComponentId\0componentId\0sendMessage\0"
    "mavlink_message_t&\0sendMessageOnLastReceivedLink\0"
    "sendMessageOnAllLinks\0onDataReceived\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_domain__MavLinkCommunicator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   62,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,
      11,    1,   70,    2, 0x0a /* Public */,
      13,    1,   73,    2, 0x0a /* Public */,
      15,    2,   76,    2, 0x0a /* Public */,
      17,    1,   81,    2, 0x0a /* Public */,
      18,    1,   84,    2, 0x0a /* Public */,
      19,    1,   87,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 8,   12,
    QMetaType::Void, 0x80000000 | 8,   14,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 6,    4,    7,
    QMetaType::Void, 0x80000000 | 16,    4,
    QMetaType::Void, 0x80000000 | 16,    4,
    QMetaType::Void, QMetaType::QByteArray,   20,

       0        // eod
};

void domain::MavLinkCommunicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MavLinkCommunicator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageReceived((*reinterpret_cast< const mavlink_message_t(*)>(_a[1]))); break;
        case 1: _t->addLink((*reinterpret_cast< AbstractLink*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 2: _t->removeLink((*reinterpret_cast< AbstractLink*(*)>(_a[1]))); break;
        case 3: _t->setSystemId((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 4: _t->setComponentId((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 5: _t->sendMessage((*reinterpret_cast< mavlink_message_t(*)>(_a[1])),(*reinterpret_cast< AbstractLink*(*)>(_a[2]))); break;
        case 6: _t->sendMessageOnLastReceivedLink((*reinterpret_cast< mavlink_message_t(*)>(_a[1]))); break;
        case 7: _t->sendMessageOnAllLinks((*reinterpret_cast< mavlink_message_t(*)>(_a[1]))); break;
        case 8: _t->onDataReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MavLinkCommunicator::*)(const mavlink_message_t & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MavLinkCommunicator::messageReceived)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject domain::MavLinkCommunicator::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_domain__MavLinkCommunicator.data,
    qt_meta_data_domain__MavLinkCommunicator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *domain::MavLinkCommunicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *domain::MavLinkCommunicator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_domain__MavLinkCommunicator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int domain::MavLinkCommunicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void domain::MavLinkCommunicator::messageReceived(const mavlink_message_t & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
