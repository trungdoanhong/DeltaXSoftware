/****************************************************************************
** Meta object code from reading C++ file 'ImageProcesser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ImageProcesser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageProcesser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageProcesser_t {
    QByteArrayData data[54];
    char stringdata0[589];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcesser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcesser_t qt_meta_stringdata_ImageProcesser = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ImageProcesser"
QT_MOC_LITERAL(1, 15, 18), // "ObjectValueChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 28), // "std::vector<cv::RotatedRect>"
QT_MOC_LITERAL(4, 64, 15), // "ObjectContainer"
QT_MOC_LITERAL(5, 80, 13), // "LoadTestImage"
QT_MOC_LITERAL(6, 94, 10), // "LoadCamera"
QT_MOC_LITERAL(7, 105, 13), // "CaptureCamera"
QT_MOC_LITERAL(8, 119, 11), // "PauseCamera"
QT_MOC_LITERAL(9, 131, 12), // "ResumeCamera"
QT_MOC_LITERAL(10, 144, 18), // "UpdateCameraScreen"
QT_MOC_LITERAL(11, 163, 7), // "SaveFPS"
QT_MOC_LITERAL(12, 171, 18), // "OpenParameterPanel"
QT_MOC_LITERAL(13, 190, 6), // "SetHSV"
QT_MOC_LITERAL(14, 197, 4), // "minH"
QT_MOC_LITERAL(15, 202, 4), // "maxH"
QT_MOC_LITERAL(16, 207, 4), // "minS"
QT_MOC_LITERAL(17, 212, 4), // "maxS"
QT_MOC_LITERAL(18, 217, 4), // "minV"
QT_MOC_LITERAL(19, 222, 4), // "maxV"
QT_MOC_LITERAL(20, 227, 12), // "SetThreshold"
QT_MOC_LITERAL(21, 240, 5), // "value"
QT_MOC_LITERAL(22, 246, 13), // "GetObjectInfo"
QT_MOC_LITERAL(23, 260, 1), // "x"
QT_MOC_LITERAL(24, 262, 1), // "y"
QT_MOC_LITERAL(25, 264, 1), // "l"
QT_MOC_LITERAL(26, 266, 1), // "w"
QT_MOC_LITERAL(27, 268, 20), // "GetPerspectivePoints"
QT_MOC_LITERAL(28, 289, 1), // "a"
QT_MOC_LITERAL(29, 291, 1), // "b"
QT_MOC_LITERAL(30, 293, 1), // "c"
QT_MOC_LITERAL(31, 295, 1), // "d"
QT_MOC_LITERAL(32, 297, 14), // "GetProcessArea"
QT_MOC_LITERAL(33, 312, 11), // "processArea"
QT_MOC_LITERAL(34, 324, 12), // "GetCalibLine"
QT_MOC_LITERAL(35, 337, 2), // "p1"
QT_MOC_LITERAL(36, 340, 2), // "p2"
QT_MOC_LITERAL(37, 343, 11), // "GetDistance"
QT_MOC_LITERAL(38, 355, 8), // "distance"
QT_MOC_LITERAL(39, 364, 13), // "GetCalibPoint"
QT_MOC_LITERAL(40, 378, 11), // "SwitchLayer"
QT_MOC_LITERAL(41, 390, 11), // "SelectLayer"
QT_MOC_LITERAL(42, 402, 2), // "id"
QT_MOC_LITERAL(43, 405, 19), // "changeAxisDirection"
QT_MOC_LITERAL(44, 425, 24), // "TurnTransformPerspective"
QT_MOC_LITERAL(45, 450, 8), // "isTurnOn"
QT_MOC_LITERAL(46, 459, 16), // "TurnCalibDisplay"
QT_MOC_LITERAL(47, 476, 5), // "state"
QT_MOC_LITERAL(48, 482, 18), // "ExpandCameraWidget"
QT_MOC_LITERAL(49, 501, 8), // "isExpand"
QT_MOC_LITERAL(50, 510, 16), // "OpenCameraWindow"
QT_MOC_LITERAL(51, 527, 17), // "CloseCameraWindow"
QT_MOC_LITERAL(52, 545, 12), // "UpdateRatios"
QT_MOC_LITERAL(53, 558, 30) // "UpdateObjectPositionOnConveyor"

    },
    "ImageProcesser\0ObjectValueChanged\0\0"
    "std::vector<cv::RotatedRect>\0"
    "ObjectContainer\0LoadTestImage\0LoadCamera\0"
    "CaptureCamera\0PauseCamera\0ResumeCamera\0"
    "UpdateCameraScreen\0SaveFPS\0"
    "OpenParameterPanel\0SetHSV\0minH\0maxH\0"
    "minS\0maxS\0minV\0maxV\0SetThreshold\0value\0"
    "GetObjectInfo\0x\0y\0l\0w\0GetPerspectivePoints\0"
    "a\0b\0c\0d\0GetProcessArea\0processArea\0"
    "GetCalibLine\0p1\0p2\0GetDistance\0distance\0"
    "GetCalibPoint\0SwitchLayer\0SelectLayer\0"
    "id\0changeAxisDirection\0TurnTransformPerspective\0"
    "isTurnOn\0TurnCalibDisplay\0state\0"
    "ExpandCameraWidget\0isExpand\0"
    "OpenCameraWindow\0CloseCameraWindow\0"
    "UpdateRatios\0UpdateObjectPositionOnConveyor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcesser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  157,    2, 0x0a /* Public */,
       6,    0,  158,    2, 0x0a /* Public */,
       7,    0,  159,    2, 0x0a /* Public */,
       8,    0,  160,    2, 0x0a /* Public */,
       9,    0,  161,    2, 0x0a /* Public */,
      10,    0,  162,    2, 0x0a /* Public */,
      11,    0,  163,    2, 0x0a /* Public */,
      12,    0,  164,    2, 0x0a /* Public */,
      13,    6,  165,    2, 0x0a /* Public */,
      20,    1,  178,    2, 0x0a /* Public */,
      22,    4,  181,    2, 0x0a /* Public */,
      22,    2,  190,    2, 0x0a /* Public */,
      27,    4,  195,    2, 0x0a /* Public */,
      32,    1,  204,    2, 0x0a /* Public */,
      34,    2,  207,    2, 0x0a /* Public */,
      37,    1,  212,    2, 0x0a /* Public */,
      39,    2,  215,    2, 0x0a /* Public */,
      40,    0,  220,    2, 0x0a /* Public */,
      41,    1,  221,    2, 0x0a /* Public */,
      43,    0,  224,    2, 0x0a /* Public */,
      44,    1,  225,    2, 0x0a /* Public */,
      46,    1,  228,    2, 0x0a /* Public */,
      48,    1,  231,    2, 0x0a /* Public */,
      50,    0,  234,    2, 0x0a /* Public */,
      51,    0,  235,    2, 0x0a /* Public */,
      52,    0,  236,    2, 0x0a /* Public */,
      53,    0,  237,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   23,   24,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   25,   26,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint, QMetaType::QPoint, QMetaType::QPoint,   28,   29,   30,   31,
    QMetaType::Void, QMetaType::QRect,   33,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint,   35,   36,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   23,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageProcesser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageProcesser *_t = static_cast<ImageProcesser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ObjectValueChanged((*reinterpret_cast< std::vector<cv::RotatedRect>(*)>(_a[1]))); break;
        case 1: _t->LoadTestImage(); break;
        case 2: _t->LoadCamera(); break;
        case 3: _t->CaptureCamera(); break;
        case 4: _t->PauseCamera(); break;
        case 5: _t->ResumeCamera(); break;
        case 6: _t->UpdateCameraScreen(); break;
        case 7: _t->SaveFPS(); break;
        case 8: _t->OpenParameterPanel(); break;
        case 9: _t->SetHSV((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 10: _t->SetThreshold((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->GetObjectInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 12: _t->GetObjectInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->GetPerspectivePoints((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2])),(*reinterpret_cast< QPoint(*)>(_a[3])),(*reinterpret_cast< QPoint(*)>(_a[4]))); break;
        case 14: _t->GetProcessArea((*reinterpret_cast< QRect(*)>(_a[1]))); break;
        case 15: _t->GetCalibLine((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 16: _t->GetDistance((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->GetCalibPoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->SwitchLayer(); break;
        case 19: _t->SelectLayer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->changeAxisDirection(); break;
        case 21: _t->TurnTransformPerspective((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->TurnCalibDisplay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->ExpandCameraWidget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->OpenCameraWindow(); break;
        case 25: _t->CloseCameraWindow(); break;
        case 26: _t->UpdateRatios(); break;
        case 27: _t->UpdateObjectPositionOnConveyor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageProcesser::*_t)(std::vector<cv::RotatedRect> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageProcesser::ObjectValueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ImageProcesser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageProcesser.data,
      qt_meta_data_ImageProcesser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageProcesser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProcesser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcesser.stringdata0))
        return static_cast<void*>(const_cast< ImageProcesser*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageProcesser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void ImageProcesser::ObjectValueChanged(std::vector<cv::RotatedRect> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
