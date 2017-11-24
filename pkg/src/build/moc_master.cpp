/****************************************************************************
** Meta object code from reading C++ file 'master.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qmaster/include/master.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'master.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Master_t {
    QByteArrayData data[22];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Master_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Master_t qt_meta_stringdata_Master = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Master"
QT_MOC_LITERAL(1, 7, 11), // "statusPrint"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "msg"
QT_MOC_LITERAL(4, 24, 10), // "sendAnswer"
QT_MOC_LITERAL(5, 35, 16), // "answer_request_t"
QT_MOC_LITERAL(6, 52, 6), // "answer"
QT_MOC_LITERAL(7, 59, 11), // "sendRawData"
QT_MOC_LITERAL(8, 71, 7), // "rawData"
QT_MOC_LITERAL(9, 79, 14), // "openConnection"
QT_MOC_LITERAL(10, 94, 15), // "closeConnection"
QT_MOC_LITERAL(11, 110, 11), // "sendRequest"
QT_MOC_LITERAL(12, 122, 19), // "abstract_request_t*"
QT_MOC_LITERAL(13, 142, 7), // "request"
QT_MOC_LITERAL(14, 150, 11), // "errorModbus"
QT_MOC_LITERAL(15, 162, 20), // "QModbusDevice::Error"
QT_MOC_LITERAL(16, 183, 5), // "error"
QT_MOC_LITERAL(17, 189, 12), // "stateChanged"
QT_MOC_LITERAL(18, 202, 20), // "QModbusDevice::State"
QT_MOC_LITERAL(19, 223, 5), // "state"
QT_MOC_LITERAL(20, 229, 8), // "onWrited"
QT_MOC_LITERAL(21, 238, 10) // "onRecieved"

    },
    "Master\0statusPrint\0\0msg\0sendAnswer\0"
    "answer_request_t\0answer\0sendRawData\0"
    "rawData\0openConnection\0closeConnection\0"
    "sendRequest\0abstract_request_t*\0request\0"
    "errorModbus\0QModbusDevice::Error\0error\0"
    "stateChanged\0QModbusDevice::State\0"
    "state\0onWrited\0onRecieved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Master[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   73,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    1,   75,    2, 0x0a /* Public */,
      14,    1,   78,    2, 0x08 /* Private */,
      17,    1,   81,    2, 0x08 /* Private */,
      20,    0,   84,    2, 0x08 /* Private */,
      21,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QByteArray,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Master::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Master *_t = static_cast<Master *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusPrint((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendAnswer((*reinterpret_cast< answer_request_t(*)>(_a[1]))); break;
        case 2: _t->sendRawData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->openConnection(); break;
        case 4: _t->closeConnection(); break;
        case 5: _t->sendRequest((*reinterpret_cast< abstract_request_t*(*)>(_a[1]))); break;
        case 6: _t->errorModbus((*reinterpret_cast< QModbusDevice::Error(*)>(_a[1]))); break;
        case 7: _t->stateChanged((*reinterpret_cast< QModbusDevice::State(*)>(_a[1]))); break;
        case 8: _t->onWrited(); break;
        case 9: _t->onRecieved(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< answer_request_t >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Master::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Master::statusPrint)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Master::*_t)(answer_request_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Master::sendAnswer)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Master::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Master::sendRawData)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Master::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Master.data,
      qt_meta_data_Master,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Master::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Master::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Master.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Master::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Master::statusPrint(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Master::sendAnswer(answer_request_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Master::sendRawData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
