/****************************************************************************
** Meta object code from reading C++ file 'mapimage.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mapimage.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapimage.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMapImageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMapImageENDCLASS = QtMocHelpers::stringData(
    "MapImage",
    "showOnlyRadar",
    "",
    "Radar",
    "Activate",
    "ShowElementCulminante",
    "ShowElementStrategique",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "setaltitude",
    "value",
    "moveImage",
    "i"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMapImageENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[9];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[9];
    char stringdata5[22];
    char stringdata6[23];
    char stringdata7[14];
    char stringdata8[11];
    char stringdata9[6];
    char stringdata10[12];
    char stringdata11[6];
    char stringdata12[10];
    char stringdata13[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMapImageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMapImageENDCLASS_t qt_meta_stringdata_CLASSMapImageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "MapImage"
        QT_MOC_LITERAL(9, 13),  // "showOnlyRadar"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 5),  // "Radar"
        QT_MOC_LITERAL(30, 8),  // "Activate"
        QT_MOC_LITERAL(39, 21),  // "ShowElementCulminante"
        QT_MOC_LITERAL(61, 22),  // "ShowElementStrategique"
        QT_MOC_LITERAL(84, 13),  // "keyPressEvent"
        QT_MOC_LITERAL(98, 10),  // "QKeyEvent*"
        QT_MOC_LITERAL(109, 5),  // "event"
        QT_MOC_LITERAL(115, 11),  // "setaltitude"
        QT_MOC_LITERAL(127, 5),  // "value"
        QT_MOC_LITERAL(133, 9),  // "moveImage"
        QT_MOC_LITERAL(143, 1)   // "i"
    },
    "MapImage",
    "showOnlyRadar",
    "",
    "Radar",
    "Activate",
    "ShowElementCulminante",
    "ShowElementStrategique",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "setaltitude",
    "value",
    "moveImage",
    "i"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMapImageENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x0a,    1 /* Public */,
       5,    1,   55,    2, 0x0a,    4 /* Public */,
       6,    1,   58,    2, 0x0a,    6 /* Public */,
       7,    1,   61,    2, 0x0a,    8 /* Public */,
      10,    1,   64,    2, 0x0a,   10 /* Public */,
      12,    1,   67,    2, 0x0a,   12 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject MapImage::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_CLASSMapImageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMapImageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMapImageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MapImage, std::true_type>,
        // method 'showOnlyRadar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ShowElementCulminante'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ShowElementStrategique'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'keyPressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>,
        // method 'setaltitude'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'moveImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MapImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MapImage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showOnlyRadar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->ShowElementCulminante((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->ShowElementStrategique((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[1]))); break;
        case 4: _t->setaltitude((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->moveImage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MapImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapImage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMapImageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int MapImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
