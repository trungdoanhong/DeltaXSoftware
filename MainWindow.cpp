#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitVariables();
}

void MainWindow::InitVariables()
{
    //------- Dasboard --------
    Dashboard = new TabDashboard();
    Dashboard->InitPanel(ui->wgLeftPanel, ui->swPageStack);
    Dashboard->InitPage(ui->tbHome, ui->pHome);
    Dashboard->InitPage(ui->tbProject, ui->pProject);
    Dashboard->InitPage(ui->tbVariable, ui->pVariable);
    Dashboard->InitPage(ui->tbSetting, ui->pSetting);
    Dashboard->InitPage(ui->tbMarket, ui->pMarket);
    Dashboard->InitPage(ui->tbDocument, ui->pDocument);
    Dashboard->InitPage(ui->tbCommunity, ui->pCommunity);
    Dashboard->InitPage(ui->tbAccount, ui->pAccount);
    Dashboard->SetSelectedState("background-color: rgb(24, 70, 139);");

    //-------- UX --------
    Ux = new UXManager();

    //-------- Variable Table -----------
    ProgramVariableManager = new VariableManager();
    ProgramVariableManager->SetTreeWidget(ui->trwProgramVariableTable);
    SoftwareManager::GetInstance()->ProgramVariableManager = ProgramVariableManager;

    //------- Project Manager --------
    RobotProjectManager = new ProjectManager();
    RobotProjectManager->InitTabManager(ui->twProjectManager);
    RobotProjectManager->InitAddNewTab(ui->tabAddNewButton);
    RobotProjectManager->IsNewTabSlotOutside = true;

    SoftwareManager::GetInstance()->RobotProjectManager = RobotProjectManager;
    //SoftwareManager::GetInstance()->RobotManagers = &RobotManagers;

    connect(RobotProjectManager, SIGNAL(NewTab_Signal(int)), SLOT(NewProject_Slot(int)));

    if (!IsLastProject())
    {
        NewProject_Slot(0);
    }

    //------------- Init Widgets -----------
    ui->trwProgramVariableTable->expandAll();
    ui->trwProgramVariableTable->setColumnWidth(0, 150);
}

bool MainWindow::IsLastProject()
{
    return false;
}

void MainWindow::NewProject_Slot(int index)
{
    QStackedWidget* stack = new QStackedWidget();

    //------- Make new robot manager ----------
    RobotManager* robotManager = new RobotManager();
    robotManager->SetMainStackedWidgetAndPages(ui->stackedWidget, ui->page, ui->pFullTabDisplay, ui->layoutFullTabDisplay);
    robotManager->SetSubStackedWidget(stack);

    robotManager->ProjectID = index - 1;

    //Insert robot manager in this project to robot manager list ----------
    RobotManagers.append(robotManager);

    //------ Create new robot project tab ---------
    RobotProjectManager->AddNewTab(stack);

    robotManager->CreatNewRobotWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}
