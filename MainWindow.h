#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TabDashboard.h"
#include "RobotWindow.h"
#include <QSettings>
#include "QStackedWidget"
#include <QList>
#include "SoftwareManager.h"
#include "VersionManager.h"
#include "Authority.h"
#include "UnityTool.h"
#include <QFileInfo>

#include <QSettings>
#include <QElapsedTimer>
#include "VarManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitVariables();
    bool IsLastProject();
    void closeEvent(QCloseEvent *event);
    void InitProjectUX();
    void InitVisible();
    void InitProjectToOperator();
    void SaveOperatorSettings();
    void LoadOperatorSettings();

    TabDashboard* Dashboard;
    ProjectManager* SoftwareProjectManager;
    QSettings* ProjectSetting;
    VersionManager* DeltaXVersionManager;
    SmartDialog* CloseDialog;
    Authority* SoftwareAuthority;

    QString LastProject = "";

    QStandardItemModel VariableTreeModel;

public slots:
    QStackedWidget* CreateNewProject(int index);
    RobotWindow *AddNewProjectAndRobot(int index);
    void OpenProjectFromFile();
    void SaveProjectToFile();
    void SelectedTab(QAbstractButton* tabButton);
    void Log(QString msg);

    void SetLoadingIconRun(bool isRun);

private slots:
    void on_pbApplyOperator_clicked();

    void on_pbSwitchProgramer_clicked();

    void on_pbAddVarToOperatorDisplay_clicked();

    void on_pbAddOperatorDisplayWidget_clicked();

    void on_pbDeleteOperatorDisplayWidget_clicked();

    void on_pbDeleteOperatorVar_clicked();

    void on_cbOperatorProject_currentIndexChanged(int index);

    void on_pbStartSystem_clicked();

    void on_pbStopSystem_clicked();

    void on_pbAddOperatorGcodeProgram_clicked();

    void on_pbDeleteOperatorGcodeProgram_clicked();

    void on_tbExpandLoggingBox_clicked();

    void on_pbUpdateVarDisplay_clicked();

private:
    void openProject(QString fullName);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
