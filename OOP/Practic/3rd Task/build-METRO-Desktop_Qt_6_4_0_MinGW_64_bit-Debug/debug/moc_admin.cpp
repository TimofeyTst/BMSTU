/****************************************************************************
** Meta object code from reading C++ file 'admin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../METRO/admin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Admin_t {
    const uint offsetsAndSize[26];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Admin_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Admin_t qt_meta_stringdata_Admin = {
    {
QT_MOC_LITERAL(0, 5), // "Admin"
QT_MOC_LITERAL(6, 10), // "show_first"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 26), // "on_pushButton_BACK_clicked"
QT_MOC_LITERAL(45, 25), // "on_pushButton_ATD_clicked"
QT_MOC_LITERAL(71, 25), // "on_pushButton_ate_clicked"
QT_MOC_LITERAL(97, 25), // "on_pushButton_aAf_clicked"
QT_MOC_LITERAL(123, 27), // "on_pushButton_aOPos_clicked"
QT_MOC_LITERAL(151, 26), // "on_pushButton_swap_clicked"
QT_MOC_LITERAL(178, 26), // "on_pushButton_DELA_clicked"
QT_MOC_LITERAL(205, 27), // "on_pushButton_dOPos_clicked"
QT_MOC_LITERAL(233, 27), // "on_pushButton_CLEAR_clicked"
QT_MOC_LITERAL(261, 26) // "on_pushButton_view_clicked"

    },
    "Admin\0show_first\0\0on_pushButton_BACK_clicked\0"
    "on_pushButton_ATD_clicked\0"
    "on_pushButton_ate_clicked\0"
    "on_pushButton_aAf_clicked\0"
    "on_pushButton_aOPos_clicked\0"
    "on_pushButton_swap_clicked\0"
    "on_pushButton_DELA_clicked\0"
    "on_pushButton_dOPos_clicked\0"
    "on_pushButton_CLEAR_clicked\0"
    "on_pushButton_view_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Admin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,

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
    QMetaType::Void,

       0        // eod
};

void Admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Admin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->show_first(); break;
        case 1: _t->on_pushButton_BACK_clicked(); break;
        case 2: _t->on_pushButton_ATD_clicked(); break;
        case 3: _t->on_pushButton_ate_clicked(); break;
        case 4: _t->on_pushButton_aAf_clicked(); break;
        case 5: _t->on_pushButton_aOPos_clicked(); break;
        case 6: _t->on_pushButton_swap_clicked(); break;
        case 7: _t->on_pushButton_DELA_clicked(); break;
        case 8: _t->on_pushButton_dOPos_clicked(); break;
        case 9: _t->on_pushButton_CLEAR_clicked(); break;
        case 10: _t->on_pushButton_view_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Admin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Admin::show_first)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject Admin::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Admin.offsetsAndSize,
    qt_meta_data_Admin,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Admin_t
, QtPrivate::TypeAndForceComplete<Admin, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Admin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Admin.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Admin::show_first()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
