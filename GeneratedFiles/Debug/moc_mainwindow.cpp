/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[88];
    char stringdata0[1430];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "ConnectDeltaRobot"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "AddNewProgram"
QT_MOC_LITERAL(4, 44, 11), // "SaveProgram"
QT_MOC_LITERAL(5, 56, 14), // "ExecuteProgram"
QT_MOC_LITERAL(6, 71, 28), // "ImportGcodeFilesFromComputer"
QT_MOC_LITERAL(7, 100, 23), // "UploadGcodeFileToServer"
QT_MOC_LITERAL(8, 124, 15), // "SearchGcodeFile"
QT_MOC_LITERAL(9, 140, 21), // "ExecuteSelectPrograms"
QT_MOC_LITERAL(10, 162, 18), // "ExecuteCurrentLine"
QT_MOC_LITERAL(11, 181, 20), // "UpdateZLineEditValue"
QT_MOC_LITERAL(12, 202, 1), // "z"
QT_MOC_LITERAL(13, 204, 20), // "UpdateWLineEditValue"
QT_MOC_LITERAL(14, 225, 1), // "w"
QT_MOC_LITERAL(15, 227, 36), // "UpdateDeltaPositionFromLineEd..."
QT_MOC_LITERAL(16, 264, 26), // "UpdateTextboxFrom2DControl"
QT_MOC_LITERAL(17, 291, 1), // "x"
QT_MOC_LITERAL(18, 293, 1), // "y"
QT_MOC_LITERAL(19, 295, 26), // "UpdateTextboxFrom3DControl"
QT_MOC_LITERAL(20, 322, 21), // "UpdatePositionControl"
QT_MOC_LITERAL(21, 344, 1), // "f"
QT_MOC_LITERAL(22, 346, 1), // "a"
QT_MOC_LITERAL(23, 348, 44), // "UpdateGlobalHomePositionValue..."
QT_MOC_LITERAL(24, 393, 14), // "UpdateVelocity"
QT_MOC_LITERAL(25, 408, 11), // "UpdateAccel"
QT_MOC_LITERAL(26, 420, 18), // "AdjustGripperAngle"
QT_MOC_LITERAL(27, 439, 5), // "angle"
QT_MOC_LITERAL(28, 445, 4), // "Grip"
QT_MOC_LITERAL(29, 450, 7), // "SetPump"
QT_MOC_LITERAL(30, 458, 5), // "value"
QT_MOC_LITERAL(31, 464, 8), // "SetLaser"
QT_MOC_LITERAL(32, 473, 4), // "Home"
QT_MOC_LITERAL(33, 478, 23), // "UpdateConvenyorPosition"
QT_MOC_LITERAL(34, 502, 20), // "DisplayGcodeVariable"
QT_MOC_LITERAL(35, 523, 20), // "QList<GcodeVariable>"
QT_MOC_LITERAL(36, 544, 14), // "gcodeVariables"
QT_MOC_LITERAL(37, 559, 17), // "SetConvenyorSpeed"
QT_MOC_LITERAL(38, 577, 20), // "GetConvenyorPosition"
QT_MOC_LITERAL(39, 598, 34), // "TurnEnoughConvenyorPositionGe..."
QT_MOC_LITERAL(40, 633, 12), // "AddGcodeLine"
QT_MOC_LITERAL(41, 646, 20), // "ChangeGcodeParameter"
QT_MOC_LITERAL(42, 667, 22), // "UpdateDetectObjectSize"
QT_MOC_LITERAL(43, 690, 20), // "UpdateCursorPosition"
QT_MOC_LITERAL(44, 711, 15), // "ConnectConveyor"
QT_MOC_LITERAL(45, 727, 15), // "SetConveyorMode"
QT_MOC_LITERAL(46, 743, 4), // "mode"
QT_MOC_LITERAL(47, 748, 21), // "SetConveyorMovingMode"
QT_MOC_LITERAL(48, 770, 22), // "SetSpeedOfPositionMode"
QT_MOC_LITERAL(49, 793, 12), // "MoveConveyor"
QT_MOC_LITERAL(50, 806, 18), // "ProcessShortcutKey"
QT_MOC_LITERAL(51, 825, 14), // "ConnectSliding"
QT_MOC_LITERAL(52, 840, 13), // "GoHomeSliding"
QT_MOC_LITERAL(53, 854, 14), // "DisableSliding"
QT_MOC_LITERAL(54, 869, 15), // "SetSlidingSpeed"
QT_MOC_LITERAL(55, 885, 18), // "SetSlidingPosition"
QT_MOC_LITERAL(56, 904, 18), // "ConnectExternalMCU"
QT_MOC_LITERAL(57, 923, 25), // "TransmitTextToExternalMCU"
QT_MOC_LITERAL(58, 949, 26), // "DisplayTextFromExternalMCU"
QT_MOC_LITERAL(59, 976, 4), // "text"
QT_MOC_LITERAL(60, 981, 16), // "TerminalTransmit"
QT_MOC_LITERAL(61, 998, 16), // "PrintReceiveData"
QT_MOC_LITERAL(62, 1015, 3), // "msg"
QT_MOC_LITERAL(63, 1019, 15), // "NoticeConnected"
QT_MOC_LITERAL(64, 1035, 14), // "RunSmartEditor"
QT_MOC_LITERAL(65, 1050, 20), // "StandardFormatEditor"
QT_MOC_LITERAL(66, 1071, 18), // "OpenGcodeReference"
QT_MOC_LITERAL(67, 1090, 16), // "ConfigConnection"
QT_MOC_LITERAL(68, 1107, 20), // "ChangeDeltaDashboard"
QT_MOC_LITERAL(69, 1128, 5), // "index"
QT_MOC_LITERAL(70, 1134, 17), // "SelectTrueTabName"
QT_MOC_LITERAL(71, 1152, 15), // "FinishedRequest"
QT_MOC_LITERAL(72, 1168, 14), // "QNetworkReply*"
QT_MOC_LITERAL(73, 1183, 5), // "reply"
QT_MOC_LITERAL(74, 1189, 20), // "ExportBlocklyToGcode"
QT_MOC_LITERAL(75, 1210, 7), // "OpenROS"
QT_MOC_LITERAL(76, 1218, 19), // "ChangeROSCameraView"
QT_MOC_LITERAL(77, 1238, 17), // "ChangeEndEffector"
QT_MOC_LITERAL(78, 1256, 18), // "ChangeRobotVersion"
QT_MOC_LITERAL(79, 1275, 15), // "AddObjectsToROS"
QT_MOC_LITERAL(80, 1291, 28), // "std::vector<cv::RotatedRect>"
QT_MOC_LITERAL(81, 1320, 15), // "ObjectContainer"
QT_MOC_LITERAL(82, 1336, 21), // "DeleteAllObjectsInROS"
QT_MOC_LITERAL(83, 1358, 7), // "ScaleUI"
QT_MOC_LITERAL(84, 1366, 27), // "ExecuteRequestsFromExternal"
QT_MOC_LITERAL(85, 1394, 7), // "request"
QT_MOC_LITERAL(86, 1402, 21), // "ChangeParentForWidget"
QT_MOC_LITERAL(87, 1424, 5) // "state"

    },
    "MainWindow\0ConnectDeltaRobot\0\0"
    "AddNewProgram\0SaveProgram\0ExecuteProgram\0"
    "ImportGcodeFilesFromComputer\0"
    "UploadGcodeFileToServer\0SearchGcodeFile\0"
    "ExecuteSelectPrograms\0ExecuteCurrentLine\0"
    "UpdateZLineEditValue\0z\0UpdateWLineEditValue\0"
    "w\0UpdateDeltaPositionFromLineEditValue\0"
    "UpdateTextboxFrom2DControl\0x\0y\0"
    "UpdateTextboxFrom3DControl\0"
    "UpdatePositionControl\0f\0a\0"
    "UpdateGlobalHomePositionValueAndControlValue\0"
    "UpdateVelocity\0UpdateAccel\0"
    "AdjustGripperAngle\0angle\0Grip\0SetPump\0"
    "value\0SetLaser\0Home\0UpdateConvenyorPosition\0"
    "DisplayGcodeVariable\0QList<GcodeVariable>\0"
    "gcodeVariables\0SetConvenyorSpeed\0"
    "GetConvenyorPosition\0"
    "TurnEnoughConvenyorPositionGetting\0"
    "AddGcodeLine\0ChangeGcodeParameter\0"
    "UpdateDetectObjectSize\0UpdateCursorPosition\0"
    "ConnectConveyor\0SetConveyorMode\0mode\0"
    "SetConveyorMovingMode\0SetSpeedOfPositionMode\0"
    "MoveConveyor\0ProcessShortcutKey\0"
    "ConnectSliding\0GoHomeSliding\0"
    "DisableSliding\0SetSlidingSpeed\0"
    "SetSlidingPosition\0ConnectExternalMCU\0"
    "TransmitTextToExternalMCU\0"
    "DisplayTextFromExternalMCU\0text\0"
    "TerminalTransmit\0PrintReceiveData\0msg\0"
    "NoticeConnected\0RunSmartEditor\0"
    "StandardFormatEditor\0OpenGcodeReference\0"
    "ConfigConnection\0ChangeDeltaDashboard\0"
    "index\0SelectTrueTabName\0FinishedRequest\0"
    "QNetworkReply*\0reply\0ExportBlocklyToGcode\0"
    "OpenROS\0ChangeROSCameraView\0"
    "ChangeEndEffector\0ChangeRobotVersion\0"
    "AddObjectsToROS\0std::vector<cv::RotatedRect>\0"
    "ObjectContainer\0DeleteAllObjectsInROS\0"
    "ScaleUI\0ExecuteRequestsFromExternal\0"
    "request\0ChangeParentForWidget\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      66,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  344,    2, 0x08 /* Private */,
       3,    0,  345,    2, 0x08 /* Private */,
       4,    0,  346,    2, 0x08 /* Private */,
       5,    0,  347,    2, 0x08 /* Private */,
       6,    0,  348,    2, 0x08 /* Private */,
       7,    0,  349,    2, 0x08 /* Private */,
       8,    0,  350,    2, 0x08 /* Private */,
       9,    0,  351,    2, 0x08 /* Private */,
      10,    0,  352,    2, 0x08 /* Private */,
      11,    1,  353,    2, 0x08 /* Private */,
      13,    1,  356,    2, 0x08 /* Private */,
      15,    0,  359,    2, 0x08 /* Private */,
      16,    4,  360,    2, 0x08 /* Private */,
      19,    4,  369,    2, 0x08 /* Private */,
      20,    6,  378,    2, 0x08 /* Private */,
      23,    4,  391,    2, 0x08 /* Private */,
      24,    0,  400,    2, 0x08 /* Private */,
      25,    0,  401,    2, 0x08 /* Private */,
      26,    1,  402,    2, 0x08 /* Private */,
      28,    0,  405,    2, 0x08 /* Private */,
      29,    1,  406,    2, 0x08 /* Private */,
      31,    1,  409,    2, 0x08 /* Private */,
      32,    0,  412,    2, 0x08 /* Private */,
      33,    2,  413,    2, 0x08 /* Private */,
      34,    1,  418,    2, 0x08 /* Private */,
      37,    0,  421,    2, 0x08 /* Private */,
      38,    0,  422,    2, 0x08 /* Private */,
      39,    0,  423,    2, 0x08 /* Private */,
      40,    0,  424,    2, 0x08 /* Private */,
      41,    0,  425,    2, 0x08 /* Private */,
      42,    0,  426,    2, 0x08 /* Private */,
      43,    2,  427,    2, 0x08 /* Private */,
      44,    0,  432,    2, 0x08 /* Private */,
      45,    1,  433,    2, 0x08 /* Private */,
      47,    1,  436,    2, 0x08 /* Private */,
      48,    0,  439,    2, 0x08 /* Private */,
      49,    0,  440,    2, 0x08 /* Private */,
      50,    0,  441,    2, 0x08 /* Private */,
      51,    0,  442,    2, 0x08 /* Private */,
      52,    0,  443,    2, 0x08 /* Private */,
      53,    0,  444,    2, 0x08 /* Private */,
      54,    0,  445,    2, 0x08 /* Private */,
      55,    0,  446,    2, 0x08 /* Private */,
      56,    0,  447,    2, 0x08 /* Private */,
      57,    0,  448,    2, 0x08 /* Private */,
      58,    1,  449,    2, 0x08 /* Private */,
      60,    0,  452,    2, 0x08 /* Private */,
      61,    1,  453,    2, 0x08 /* Private */,
      63,    0,  456,    2, 0x08 /* Private */,
      64,    0,  457,    2, 0x08 /* Private */,
      65,    0,  458,    2, 0x08 /* Private */,
      66,    0,  459,    2, 0x08 /* Private */,
      67,    0,  460,    2, 0x08 /* Private */,
      68,    1,  461,    2, 0x08 /* Private */,
      70,    1,  464,    2, 0x08 /* Private */,
      71,    1,  467,    2, 0x08 /* Private */,
      74,    0,  470,    2, 0x08 /* Private */,
      75,    0,  471,    2, 0x08 /* Private */,
      76,    1,  472,    2, 0x08 /* Private */,
      77,    1,  475,    2, 0x08 /* Private */,
      78,    1,  478,    2, 0x08 /* Private */,
      79,    1,  481,    2, 0x08 /* Private */,
      82,    0,  484,    2, 0x08 /* Private */,
      83,    0,  485,    2, 0x08 /* Private */,
      84,    1,  486,    2, 0x08 /* Private */,
      86,    1,  489,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   17,   18,   12,   14,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   17,   18,   12,   14,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   17,   18,   12,   14,   21,   22,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   17,   18,   12,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   17,   18,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   46,
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
    QMetaType::Void, QMetaType::QString,   59,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   69,
    QMetaType::Void, QMetaType::Int,   69,
    QMetaType::Void, 0x80000000 | 72,   73,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   69,
    QMetaType::Void, QMetaType::Int,   69,
    QMetaType::Void, QMetaType::Int,   69,
    QMetaType::Void, 0x80000000 | 80,   81,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   85,
    QMetaType::Void, QMetaType::Bool,   87,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ConnectDeltaRobot(); break;
        case 1: _t->AddNewProgram(); break;
        case 2: _t->SaveProgram(); break;
        case 3: _t->ExecuteProgram(); break;
        case 4: _t->ImportGcodeFilesFromComputer(); break;
        case 5: _t->UploadGcodeFileToServer(); break;
        case 6: _t->SearchGcodeFile(); break;
        case 7: _t->ExecuteSelectPrograms(); break;
        case 8: _t->ExecuteCurrentLine(); break;
        case 9: _t->UpdateZLineEditValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->UpdateWLineEditValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->UpdateDeltaPositionFromLineEditValue(); break;
        case 12: _t->UpdateTextboxFrom2DControl((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 13: _t->UpdateTextboxFrom3DControl((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 14: _t->UpdatePositionControl((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6]))); break;
        case 15: _t->UpdateGlobalHomePositionValueAndControlValue((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 16: _t->UpdateVelocity(); break;
        case 17: _t->UpdateAccel(); break;
        case 18: _t->AdjustGripperAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->Grip(); break;
        case 20: _t->SetPump((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->SetLaser((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->Home(); break;
        case 23: _t->UpdateConvenyorPosition((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 24: _t->DisplayGcodeVariable((*reinterpret_cast< QList<GcodeVariable>(*)>(_a[1]))); break;
        case 25: _t->SetConvenyorSpeed(); break;
        case 26: _t->GetConvenyorPosition(); break;
        case 27: _t->TurnEnoughConvenyorPositionGetting(); break;
        case 28: _t->AddGcodeLine(); break;
        case 29: _t->ChangeGcodeParameter(); break;
        case 30: _t->UpdateDetectObjectSize(); break;
        case 31: _t->UpdateCursorPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 32: _t->ConnectConveyor(); break;
        case 33: _t->SetConveyorMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->SetConveyorMovingMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->SetSpeedOfPositionMode(); break;
        case 36: _t->MoveConveyor(); break;
        case 37: _t->ProcessShortcutKey(); break;
        case 38: _t->ConnectSliding(); break;
        case 39: _t->GoHomeSliding(); break;
        case 40: _t->DisableSliding(); break;
        case 41: _t->SetSlidingSpeed(); break;
        case 42: _t->SetSlidingPosition(); break;
        case 43: _t->ConnectExternalMCU(); break;
        case 44: _t->TransmitTextToExternalMCU(); break;
        case 45: _t->DisplayTextFromExternalMCU((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 46: _t->TerminalTransmit(); break;
        case 47: _t->PrintReceiveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 48: _t->NoticeConnected(); break;
        case 49: _t->RunSmartEditor(); break;
        case 50: _t->StandardFormatEditor(); break;
        case 51: _t->OpenGcodeReference(); break;
        case 52: _t->ConfigConnection(); break;
        case 53: _t->ChangeDeltaDashboard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->SelectTrueTabName((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->FinishedRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 56: _t->ExportBlocklyToGcode(); break;
        case 57: _t->OpenROS(); break;
        case 58: _t->ChangeROSCameraView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->ChangeEndEffector((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->ChangeRobotVersion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: _t->AddObjectsToROS((*reinterpret_cast< std::vector<cv::RotatedRect>(*)>(_a[1]))); break;
        case 62: _t->DeleteAllObjectsInROS(); break;
        case 63: _t->ScaleUI(); break;
        case 64: _t->ExecuteRequestsFromExternal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 65: _t->ChangeParentForWidget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 55:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
