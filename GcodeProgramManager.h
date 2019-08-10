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

class GcodeVariable
{
public:
	QString Name;
	float Value;
};

class GcodeProgramManager : public QObject
{
	Q_OBJECT

public:
	GcodeProgramManager();
	~GcodeProgramManager();
	GcodeProgramManager(QWidget* container, CodeEditor* gcodeArea, ConnectionManager* deltaPort = NULL, DeltaVisualizer* deltaVisualize = NULL);
	void AddGcodeLine(QString line);
	void AddG01(float  x, float y, float z);
	void AddG28();
	void AddM204(float accel);
	void AddNewProgram();
	void LoadPrograms();
	void ExecuteGcode(QString gcodes);
	void Stop();

	QWidget* wgProgramContainer;
	CodeEditor* pteGcodeArea;

	GcodeProgram* SelectingProgram = NULL;
	int ProgramCounter = 0;
	QVector<GcodeProgram*>* ProgramList;

public slots:
	void ChangeSelectingProgram(GcodeProgram* ptr);
	void SaveGcodeIntoFile();
	void DeleteProgram(GcodeProgram* ptr);
	void TransmitNextGcode();
	void UpdateSystemVariable(QString name, float value);
	void SetStartingGcodeEditorCursor(QString value);

signals:
	void OutOfObjectVariable();
	void JustUpdateVariable(QList<GcodeVariable> gcodeVariables);
	void MoveToNewPosition(float x, float y, float z, float w);

private:
	ConnectionManager* deltaConnection;
	DeltaVisualizer* deltaParameter;
	QList<GcodeVariable> gcodeVariables;

	QList<QString> gcodeList;
	int gcodeOrder = 0;
	QString startingMode = "Begin";
	int currentGcodeEditorCursor = 0;
	int returnSubProPointer[20];
	int returnPointerOrder = -1;
	QString currentLine;

	float GetVariableValue(QString name);
	bool findExeGcodeAndTransmit();
	float calculateExpressions(QString expression);
	void SaveGcodeVariable(GcodeVariable gvar);
	void updatePositionIntoSystemVariable(QString statement);
	QString getLeftWord(QString s, int pos);
	QString getRightWord(QString s, int pos);
	QString deleteSpaces(QString s);
	bool isNotNegative(QString s);
};

