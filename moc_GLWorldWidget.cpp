/****************************************************************************
** Meta object code from reading C++ file 'GLWorldWidget.h'
**
** Created: Mon Jun 6 11:21:53 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GLWorldWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWorldWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWorldWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      33,   14,   14,   14, 0x05,
      49,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   14,   14,   14, 0x0a,
      86,   14,   14,   14, 0x0a,
     103,   14,   14,   14, 0x0a,
     122,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWorldWidget[] = {
    "GLWorldWidget\0\0insertOnTree(int)\0"
    "findOnTree(int)\0deleteOnTree(int)\0"
    "btnInsertClicked()\0btnFindClicked()\0"
    "btnDeleteClicked()\0randomActive(int)\0"
};

const QMetaObject GLWorldWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GLWorldWidget,
      qt_meta_data_GLWorldWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWorldWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWorldWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWorldWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWorldWidget))
        return static_cast<void*>(const_cast< GLWorldWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GLWorldWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: insertOnTree((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: findOnTree((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: deleteOnTree((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: btnInsertClicked(); break;
        case 4: btnFindClicked(); break;
        case 5: btnDeleteClicked(); break;
        case 6: randomActive((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GLWorldWidget::insertOnTree(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLWorldWidget::findOnTree(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GLWorldWidget::deleteOnTree(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
