/****************************************************************************
** Meta object code from reading C++ file 'chat_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../chat_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_chat_form_t {
    QByteArrayData data[12];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chat_form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chat_form_t qt_meta_stringdata_chat_form = {
    {
QT_MOC_LITERAL(0, 0, 9), // "chat_form"
QT_MOC_LITERAL(1, 10, 13), // "slotReadyRead"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(4, 51, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 73, 22), // "on_chat_form_destroyed"
QT_MOC_LITERAL(6, 96, 10), // "closeEvent"
QT_MOC_LITERAL(7, 107, 12), // "QCloseEvent*"
QT_MOC_LITERAL(8, 120, 5), // "event"
QT_MOC_LITERAL(9, 126, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(10, 150, 4), // "arg1"
QT_MOC_LITERAL(11, 155, 27) // "on_lineEdit_editingFinished"

    },
    "chat_form\0slotReadyRead\0\0"
    "on_lineEdit_returnPressed\0"
    "on_pushButton_clicked\0on_chat_form_destroyed\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_lineEdit_textChanged\0arg1\0"
    "on_lineEdit_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chat_form[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       9,    1,   56,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void chat_form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<chat_form *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotReadyRead(); break;
        case 1: _t->on_lineEdit_returnPressed(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_chat_form_destroyed(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_editingFinished(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject chat_form::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_chat_form.data,
    qt_meta_data_chat_form,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *chat_form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chat_form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_chat_form.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int chat_form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
