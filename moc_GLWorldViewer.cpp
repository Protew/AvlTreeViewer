/****************************************************************************
** Meta object code from reading C++ file 'GLWorldViewer.h'
**
** Created: Mon Jun 6 11:21:52 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GLWorldViewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWorldViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWorldViewer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      32,   14,   14,   14, 0x0a,
      50,   14,   14,   14, 0x0a,
      66,   14,   14,   14, 0x0a,
      78,   14,   14,   14, 0x0a,
      88,   14,   14,   14, 0x0a,
     100,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWorldViewer[] = {
    "GLWorldViewer\0\0quickActive(int)\0"
    "followActive(int)\0setNodeRay(int)\0"
    "Insert(int)\0Find(int)\0Delete(int)\0"
    "ClearAll()\0"
};

const QMetaObject GLWorldViewer::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWorldViewer,
      qt_meta_data_GLWorldViewer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWorldViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWorldViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWorldViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWorldViewer))
        return static_cast<void*>(const_cast< GLWorldViewer*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWorldViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quickActive((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: followActive((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setNodeRay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: Insert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: Find((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: Delete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: ClearAll(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
