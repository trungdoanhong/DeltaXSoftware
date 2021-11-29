#pragma once

#include <qwidget.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qscrollarea.h>
#include <qobject.h>
#include <qlistwidget.h>
#include <vector>
#include <qlayout.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qplaintextedit.h>
#include <qurl.h>
#include <qvector.h>
#include <qdir.h>
#include <UnityTool.h>
#include <GcodeProgram.h>
#include <qtimer.h>
#include <ConnectionManager.h>
#include <DeltaVisualizer.h>
#include <codeeditor.h>
#include <qscrollarea.h>
#include <qscrollbar.h>
#include "RobotWindow.h"
#include <QtMath>
#include "ScurveInterpolator.h"
#include <QSettings>

class RobotWindow;

class GcodeVariable
{
public:
    GcodeVariable()
    {
        Name = "";
        Value = "0";
    };
    GcodeVariable(QString name, QString value)
    {
        Name = name;
        Value = value;
    }
	QString Name;
    QString Value;
};

class GcodeProgramManager : public QObject
{
	Q_OBJECT

public:
	GcodeProgramManager(RobotWindow *parent);
	~GcodeProgramManager();
	GcodeProgramManager(RobotWindow *parent, QScrollArea* scrolArea, QWidget* container, CodeEditor* gcodeArea, QPushButton* executeButton, ConnectionManager* deltaPort = NULL, DeltaVisualizer* deltaVisualize = NULL);
	void AddGcodeLine(QString line);
	void AddG01(float  x, float y, float z);
	void AddG28();
	void AddM204(float accel);
    GcodeProgram* AddNewProgram();
	void LoadPrograms();
    void LoadPrograms(QDir dir);
	void ExecuteGcode(QString gcodes, bool isFromGE = false);
    void Stop();

    void SaveSettings(QSettings* setting);
    void LoadSettings(QSettings* setting);

	QWidget* wgProgramContainer;
	QScrollArea* saProgramFilesScrollArea;
	CodeEditor* pteGcodeArea;
	QPushButton* pbExecuteGcodes;
    QLineEdit* leGcodeProgramPath = NULL;

	GcodeProgram* selectingProgram = NULL;
	int ProgramCounter = 0;
	QVector<GcodeProgram*>* ProgramList = NULL;

    /*!
     Parameter: - Conveyor: speed, direction
                - Robot: speed, acceleration, start speed, end speed, position
     */
    bool IsConveyorSync = false;
    float syncStartArea = -100;
    float syncEndArea = 100;

	bool IsFromOtherGcodeProgram = false;
	GcodeProgramManager* OutsideGcodeProgramManager = NULL;
	GcodeProgramManager* InsideGcodeProgramManager = NULL;

    QList<GcodeVariable> GcodeVariables;

    Scurve_Interpolator DeltaXSMoving;

public slots:
	void ChangeSelectingProgram(GcodeProgram* ptr);
	void SaveGcodeIntoFile();
    void SaveGcodeIntoFile(GcodeProgram* program);
	void DeleteProgram(GcodeProgram* ptr);
	void EraserAllProgramItems();
	void SortProgramFiles();
	void RefreshGcodeProgramList();
	void TransmitNextGcode();
    void UpdateSystemVariable(QString name, QString value);
	void RespondVariableValue(QIODevice* sender, QString name);
    void SetStartingGcodeEditorCursor(QString value);

    void SaveGcodeVariable(GcodeVariable gvar);
    void SaveGcodeVariable(QString name, QString value);
    void SaveGcodeVariable(QString cmd);

    void SelectGcodeProgramPath();

signals:
	void OutOfObjectVariable();
    void JustUpdateVariable();
    void MoveToNewPosition(float x, float y, float z, float w, float u, float v, float f, float a, float s, float e);
	void FinishExecuteGcodes();

	void DeleteAllObjects();
	void DeleteObject1();
	void PauseCamera();
	void CaptureCamera();
	void ResumeCamera();

private:
	ConnectionManager* deltaConnection;
    DeltaVisualizer* deltaParameter;

	int sortMethod = 0;

	bool isFromGcodeEditor = false;
	bool isFileProgramRunning = false;

	QList<QString> gcodeList;
	int gcodeOrder = 0;
	QString startingMode = "Begin";
	int currentGcodeEditorCursor = 0;
	int returnSubProPointer[20];
	int returnPointerOrder = -1;
	QString currentLine;

	RobotWindow* mParent;

    QString GetVariableValue(QString name);
    float GetResultOfMathFunction(QString expression);
	bool isGlobalVariable(QString name);
	bool isConveyorGcode(QString gcode);
	bool isSlidingGcode(QString gcode);
	bool isMovingGcode(QString gcode);
	bool findExeGcodeAndTransmit();
    QString calculateExpressions(QString expression);
	void updatePositionIntoSystemVariable(QString statement);
	QString getLeftWord(QString s, int pos);
	QString getRightWord(QString s, int pos);
	QString deleteSpaces(QString s);
	bool isNotNegative(QString s);

    QString convertGcodeToSyncConveyor(QString gcode);

    QString getTrueProgramPath();
};

