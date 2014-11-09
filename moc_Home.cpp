/****************************************************************************
** Meta object code from reading C++ file 'Home.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Includes/Home.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Home.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Home[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      19,    5,    5,    5, 0x08,
      34,    5,    5,    5, 0x08,
      48,    5,    5,    5, 0x08,
      67,    5,    5,    5, 0x08,
      77,    5,    5,    5, 0x08,
      92,    5,    5,    5, 0x08,
     105,    5,    5,    5, 0x08,
     118,    5,    5,    5, 0x08,
     135,  133,    5,    5, 0x08,
     162,    5,    5,    5, 0x08,
     204,    5,    5,    5, 0x08,
     220,    5,    5,    5, 0x08,
     236,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Home[] = {
    "Home\0\0addContact()\0invitContact()\0"
    "callContact()\0videoCallContact()\0"
    "hangHup()\0changeOnline()\0changeAway()\0"
    "changeBusy()\0showNewField()\0,\0"
    "updatePlayerUI(QImage,int)\0"
    "sendFrameTo(std::vector<unsigned char*>*)\0"
    "recvFrameFrom()\0threadReceive()\0"
    "threadCall()\0"
};

void Home::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData Home::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Home::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Home,
      qt_meta_data_Home, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Home::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Home::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Home::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Home))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
