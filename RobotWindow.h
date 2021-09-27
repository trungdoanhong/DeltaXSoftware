#ifndef ROBOTWINDOW_H
#define ROBOTWINDOW_H

#include <QMainWindow>
#include "ConnectionManager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <stdio.h>
#include <UnityTool.h>
#include <GcodeProgramManager.h>
#include <DeltaVisualizer.h>
#include <qmath.h>
#include <hsvwindow.h>
#include <qfiledialog.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <ImageUnity.h>
#include "ObjectDetector.h"
#include <GcodeReference.h>
#include <DrawingExporter.h>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QVersionNumber>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QInputDialog>
#include <QUrl>
#include <TCPConnectionManager.h>
//#include <ROS.h>
#include <QCloseEvent>
#include <ObjectVariableTable.h>
#include <QProcess>
#include <QSettings>
#include <QtMultimedia/QCameraInfo>
#include <QMovie>
#include "sdk/DeltaXPlugin.h"
#include <QPluginLoader>
#include "SmartDialog.h"
#include <QElapsedTimer>

#define JOY_STICK

#ifdef Q_OS_WIN
    #ifdef JOY_STICK
        #include <QJoysticks.h>
    #endif
#endif

#include <QMap>
#include <QLayout>
#include <QStackedWidget>

#include "Robot.h"
#include "robotmanager.h"
#include "SoftwareManager.h"

#include "ComDevice.h"

class RobotWindow;
class ObjectDetector;
class GcodeProgramManager;
class GcodeVariable;
class ROS;
class RobotManager;

namespace Ui {
    class RobotWindow;
}

class RobotWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit RobotWindow(QWidget *parent = 0);
    ~RobotWindow();

    //----- Init ----
	void InitEvents();
    void InitVariables();
    void LoadPlugin();

    void InitTabs();
    void SetID(int id);
    void SetName(QString name);

    // ----- Event ----
    void DisablePositionUpdatingEvents();
    void EnablePositionUpdatingEvents();
    void closeEvent(QCloseEvent *event);

    // ---- UI pointer -----
    void SetMainStackedWidgetAndPages(QStackedWidget* mainStack, QWidget* mainPage, QWidget* fullDisplayPage, QLayout* fullDisplayLayout);
    void SetSubStackedWidget(QStackedWidget* subStackedWidget);

    // ---- MODULE ----

    //---- Connection ----
	ConnectionManager* DeltaConnectionManager;
    ConnectionManager* CurrentDeltaPort;
    QNetworkAccessManager *HttpManager;

    // ---- Gcode ----
	GcodeProgramManager* DeltaGcodeManager;
    QTimer* EditorTimer;

    // ---- Robot ----
    Robot RobotParamter;
    RobotManager* RobotObjectManager;
    RobotManager* RobotManagerPointer = NULL;
    DeltaVisualizer *Delta2DVisualizer;
    QTimer* ShortcutKeyTimer;

    int ID = 0;
    QString Name = "robot 1";
    QString SoftwareVersion = "0.9.5";

    // ---- Vision ----

    ObjectDetector* DeltaImageProcesser;
    ObjectVariableTable* TrackingObjectTable;
    COMDevice* COMEncoder;
    QElapsedTimer ElapsedTimeEncoder;
    QTimer* ConvenyorTimer;

    float EncoderPositionAtCameraCapture = 0;

    // ---- Drawing ----
    DrawingExporter* DeltaDrawingExporter;

    // ---- ROS ----
	ROS* DeltaXROS;

    // ---- Loading ----
    QLabel* lbLoadingPopup;
    QMovie *mvLoadingPopup;

    // ---- Menu ----
	QAction* SelectedAction = NULL;

    // ---- Display -----
	float UIScale = 1;
    SmartDialog* CloseDialog;

    QStackedWidget* MainWindowStackedWidget;
    QWidget* MainWindowPage;
    QWidget* FullDisplayPage;
    QLayout* FullDisplayLayout;

    QStackedWidget* SubWindowStackedWidget;

private slots:
    // ---- Setting ----
    void SaveSetting();
    void LoadSetting();

    // ---- Robot Connection ----
    void ConnectDeltaRobot();
    void NoticeConnected();

    void ConfigConnection();
    void ChangeDeltaDashboard(int index);
    void SelectTrueTabName(int index);

    // ---- Gcode Editor ----
	void AddNewProgram();
	void SaveProgram();
	void ExecuteProgram();
	void ImportGcodeFilesFromComputer();
	void UploadGcodeFileToServer();
	void SearchGcodeFile();

	void ExecuteSelectPrograms();
	void ExecuteCurrentLine();
    void AddGcodeLine();

    void ChangeGcodeParameter();
    void RunSmartEditor();
    void StandardFormatEditor();

    void OpenGcodeReference();
    void ExportBlocklyToGcode();
    void ExecuteRequestsFromExternal(QString request);

    // ---- Robot Controller ----
    void Home();
	void UpdateZLineEditValue(int z);
	void UpdateWLineEditValue(int w);
	void UpdateDeltaPositionFromLineEditValue();
    void UpdatePositionToLabel();
    void UpdateTextboxFrom2DControl(float x, float y, float z, float w, float u, float v);
    void UpdateTextboxFrom3DControl(float x, float y, float z, float w, float u, float v);
    void UpdatePositionControl(float x, float y, float z, float w, float u, float v, float f, float a, float s, float e);
    void UpdateGlobalHomePositionValueAndControlValue(float x, float y, float z, float w, float u, float v);
	void UpdateVelocity();
	void UpdateAccel();
    void UpdateStartSpeed();
    void UpdateEndSpeed();
	void AdjustGripperAngle(int angle);
	void Grip();


    //------ End Effector Robot -------
	void SetPump(bool value);
    void SetLaser(bool value);
    void SetOnOffOutput(bool result);
    void SetValueOutput();
    void RequestValueInput();
    void GetValueInput(QString response);

    //----- Variable -----
	void DisplayGcodeVariable(QList<GcodeVariable> gcodeVariables);

    // ---- Conveyor ----
    void ConnectConveyor();
    void SetConveyorMode(int mode);
    void SetConveyorMovingMode(int mode);
    void SetSpeedOfPositionMode();
    void MoveConveyor();

    void SetConvenyorSpeed();
    void ConnectEncoder();
    void ResetEncoderPosition();
    void ReceiveConveyorResponse(QString response);

    void UpdateDetectObjectSize();
    void UpdateCursorPosition(float x, float y);

    void ProcessShortcutKey();
    void CalculateLostEncoderPositionWhenDetecting();

    void ProcessDetectedObjectFromExternalAI(QString msg);
    void SaveEncoderPositionWhenExternalAIDetect();
	
    // ---- Slider ----
	void ConnectSliding();
	void GoHomeSliding();
	void DisableSliding();
	void SetSlidingSpeed();
	void SetSlidingPosition();

    // ---- External Device ----
	void ConnectExternalMCU();
	void TransmitTextToExternalMCU();
    void DisplayTextFromExternalMCU(QString text);

    // ---- Termite ----
	void TerminalTransmit();
	void PrintReceiveData(QString msg);

    // ---- Connection ----
	void FinishedRequest(QNetworkReply *reply);

    // ---- ROS ----
	void OpenROS();
	void ChangeROSCameraView(int index);
	void ChangeEndEffector(int index);
	void ChangeRobotVersion(int index);
	void AddObjectsToROS(std::vector<cv::RotatedRect> ObjectContainer);
	void DeleteAllObjectsInROS();

    // ----- Display ----
	void ScaleUI();    
	void ChangeParentForWidget(bool state);

    void OpenLoadingPopup();
    void CloseLoadingPopup();

    void MaximizeTab(int index);
#ifdef Q_OS_WIN
    #ifdef JOY_STICK
        //--------Joystick-----------
        void ProcessJoystickButton(const QJoystickButtonEvent& event);
        void ProcessJoystickAxis(const QJoystickAxisEvent& event);
        void ProcessJoystickPOV(const QJoystickPOVEvent& event);
    #endif
#endif

private:

    // ---- Gcode Editor -----
	QString boldKey(QString key, QString htmlText);
	QString boldPlusKey(QString key, QString plus, QString htmlText);
	QString italyKey(QString key, QString htmlText);
	QString replaceHtmlSection(QString start, int offset, int maxlen, QString finish, QString beforeSection, QString afterSection, QString htmlText);

    // ---- Display ----
    bool openConnectionDialog(QSerialPort* comPort, QTcpSocket* socket,QPushButton* connectButton, QLabel* comNameInfo = NULL);

	void hideExampleWidgets();

    // ---- Test ----
	void interpolateCircle();
	void makeEffectExample();

    //--------- Controller -------
#ifdef Q_OS_WIN
    #ifdef JOY_STICK
        QJoysticks *joystick;
    #endif
#endif
    //--------- Utils ----------
    void sendGcode(QString prefix, QString para1, QString para2);
    QObject* getObjectByName(QObject* parent, QString name);
    void initInputValueLabels();

    //--------- Plugin -----------
    QStringList getPlugins(QString path);
    void initPlugins(QStringList plugins);
    QList<DeltaXPlugin*>* getPluginList();

    QList<DeltaXPlugin*>* pluginList;

    //---- Widget Pointer ----

    QList<QLabel*>* lbInputValues;
    QLineEdit* leChessPoints[4][2];

    //----- Event Robot Controller ----
    QString positionEmitter = "";

public:
    Ui::RobotWindow *ui;
};


#endif // ROBOTWINDOW_H
