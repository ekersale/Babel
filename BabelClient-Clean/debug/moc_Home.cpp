/****************************************************************************
** Meta object code from reading C++ file 'Home.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Includes/Home.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Home.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Home_t {
    QByteArrayData data[17];
    char stringdata[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Home_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Home_t qt_meta_stringdata_Home = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 10),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 12),
QT_MOC_LITERAL(4, 30, 11),
QT_MOC_LITERAL(5, 42, 16),
QT_MOC_LITERAL(6, 59, 7),
QT_MOC_LITERAL(7, 67, 12),
QT_MOC_LITERAL(8, 80, 10),
QT_MOC_LITERAL(9, 91, 10),
QT_MOC_LITERAL(10, 102, 12),
QT_MOC_LITERAL(11, 115, 14),
QT_MOC_LITERAL(12, 130, 11),
QT_MOC_LITERAL(13, 142, 28),
QT_MOC_LITERAL(14, 171, 13),
QT_MOC_LITERAL(15, 185, 13),
QT_MOC_LITERAL(16, 199, 10)
    },
    "Home\0addContact\0\0invitContact\0callContact\0"
    "videoCallContact\0hangHup\0changeOnline\0"
    "changeAway\0changeBusy\0showNewField\0"
    "updatePlayerUI\0sendFrameTo\0"
    "std::vector<unsigned char*>*\0recvFrameFrom\0"
    "threadReceive\0threadCall"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Home[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    2,   93,    2, 0x08 /* Private */,
      12,    1,   98,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Home::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Home *_t = static_cast<Home *>(_o);
        switch (_id) {
        case 0: _t->addContact(); break;
        case 1: _t->invitContact(); break;
        case 2: _t->callContact(); break;
        case 3: _t->videoCallContact(); break;
        case 4: _t->hangHup(); break;
        case 5: _t->changeOnline(); break;
        case 6: _t->changeAway(); break;
        case 7: _t->changeBusy(); break;
        case 8: _t->showNewField(); break;
        case 9: _t->updatePlayerUI((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->sendFrameTo((*reinterpret_cast< std::vector<unsigned char*>*(*)>(_a[1]))); break;
        case 11: _t->recvFrameFrom(); break;
        case 12: _t->threadReceive(); break;
        case 13: _t->threadCall(); break;
        default: ;
        }
    }
}

const QMetaObject Home::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Home.data,
      qt_meta_data_Home,  qt_static_metacall, 0, 0}
};


const QMetaObject *Home::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Home::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Home.stringdata))
        return static_cast<void*>(const_cast< Home*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Home::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
