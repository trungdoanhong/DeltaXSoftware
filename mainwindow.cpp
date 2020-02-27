﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitVariables();
    InitEvents();

	hideExampleWidgets();
	//interpolateCircle();
	//makeEffectExample();
}

MainWindow::~MainWindow()
{
	if (DeltaXMainWindows == NULL)
	{
		delete ui;
		return;
	}

	for (int i = 0; i < DeltaXMainWindows->size(); i++)
	{
		DeltaXMainWindows->at(i)->ui->twDeltaManager->removeTab(ID);
	}

	for (int i = 0; i < DeltaXMainWindows->size(); i++)
	{
		DeltaXMainWindows->at(i)->ID = i;
		DeltaXMainWindows->at(i)->ui->lbID->setText(QString("ID: ") + QString::number(i));
	}

	DeltaXMainWindows->removeAt(ID);
	Debugs.removeAt(ID);

	delete SelectedAction;

	for (int i = 0; i < DeltaXMainWindows->size(); i++)
	{
		DeltaXMainWindows->at(i)->ID = i;
		DeltaXMainWindows->at(i)->ui->lbID->setText(QString("ID: ") + QString::number(i));
	}

	SelectTrueTabName(0);

    delete ui;
}

void MainWindow::InitEvents()
{
    connect(ui->pbConnect, SIGNAL(clicked(bool)), this, SLOT(ConnectDeltaRobot()));
	connect(ui->pbAddNewProgram, SIGNAL(clicked(bool)), this, SLOT(AddNewProgram()));
	connect(ui->pbRefreshGcodeFiles, SIGNAL(clicked(bool)), DeltaGcodeManager, SLOT(RefreshGcodeProgramList()));
	connect(ui->pbSortGcodeFiles, SIGNAL(clicked(bool)), DeltaGcodeManager, SLOT(SortProgramFiles()));
	connect(ui->pbSaveGcode, SIGNAL(clicked(bool)), this, SLOT(SaveProgram()));
	connect(ui->pbExecuteGcodes, SIGNAL(clicked(bool)), this, SLOT(ExecuteProgram()));
	connect(ui->pteGcodeArea, SIGNAL(cursorPositionChanged()), this, SLOT(ExecuteCurrentLine()));
	connect(ui->cbPositionToExecuteGcode, SIGNAL(currentIndexChanged(const QString &)), DeltaGcodeManager, SLOT(SetStartingGcodeEditorCursor(QString)));

	connect(ui->pbHome, SIGNAL(clicked(bool)), this, SLOT(Home()));
	connect(ui->pbW, SIGNAL(clicked(bool)), this, SLOT(UpdateDeltaPositionFromLineEditValue()));
	connect(ui->pbZ, SIGNAL(clicked(bool)), this, SLOT(UpdateDeltaPositionFromLineEditValue()));
	connect(ui->pbY, SIGNAL(clicked(bool)), this, SLOT(UpdateDeltaPositionFromLineEditValue()));
	connect(ui->pbX, SIGNAL(clicked(bool)), this, SLOT(UpdateDeltaPositionFromLineEditValue()));
	connect(ui->hsGripperAngle, SIGNAL(valueChanged(int)), this, SLOT(AdjustGripperAngle(int)));
	connect(ui->pbGrip, SIGNAL(clicked(bool)), this, SLOT(Grip()));
	connect(ui->pbPump, SIGNAL(clicked(bool)), this, SLOT(SetPump(bool)));
	connect(ui->pbLaser, SIGNAL(clicked(bool)), this, SLOT(SetLaser(bool)));

	//connect(ui->pbSetSpeedConvenyor, SIGNAL(clicked(bool)), this, SLOT(SetConvenyorSpeed()));
	connect(ui->pbGetPositionConvenyor, SIGNAL(clicked(bool)), this, SLOT(GetConvenyorPosition()));

	connect(ui->pbConveyorConnect, SIGNAL(clicked(bool)), this, SLOT(ConnectConveyor()));
	connect(ui->cbConveyorMode, SIGNAL(currentIndexChanged(int)), this, SLOT(SetConveyorMode(int)));
	connect(ui->pbConveyorMove, SIGNAL(clicked(bool)), this, SLOT(MoveConveyor()));

	connect(ui->pbSlidingConnect, SIGNAL(clicked(bool)), this, SLOT(ConnectSliding()));
	connect(ui->pbSlidingHome, SIGNAL(clicked(bool)), this, SLOT(GoHomeSliding()));
	connect(ui->pbSlidingDisable, SIGNAL(clicked(bool)), this, SLOT(DisableSliding()));
	connect(ui->leSlidingSpeed, SIGNAL(returnPressed()), this, SLOT(SetSlidingSpeed()));
	connect(ui->leSlidingPosition, SIGNAL(returnPressed()), this, SLOT(SetSlidingPosition()));

	connect(ui->pbUp, SIGNAL(clicked(bool)), DeltaParameter, SLOT(MoveUp()));
	connect(ui->pbDown, SIGNAL(clicked(bool)), DeltaParameter, SLOT(MoveDown()));
	connect(ui->pbForward, SIGNAL(clicked(bool)), DeltaParameter, SLOT(MoveForward()));
	connect(ui->pbBackward, SIGNAL(clicked(bool)), DeltaParameter, SLOT(MoveBackward()));
	connect(ui->pbLeft, SIGNAL(clicked(bool)), DeltaParameter, SLOT(MoveLeft()));
	connect(ui->pbRight, SIGNAL(clicked(bool)), DeltaParameter, SLOT(MoveRight()));
	connect(ui->leVelocity, SIGNAL(returnPressed()), this, SLOT(UpdateVelocity()));
	connect(ui->leAccel, SIGNAL(returnPressed()), this, SLOT(UpdateAccel()));

	connect(ui->vsZAdjsution, SIGNAL(valueChanged(int)), this, SLOT(UpdateZLineEditValue(int)));
	connect(ui->vsZAdjsution, SIGNAL(sliderReleased()), this, SLOT(UpdateDeltaPositionFromLineEditValue()));
	connect(ui->vsAngleAdjsution, SIGNAL(valueChanged(int)), this, SLOT(UpdateWLineEditValue(int)));
	connect(ui->vsAngleAdjsution, SIGNAL(sliderReleased()), this, SLOT(UpdateDeltaPositionFromLineEditValue()));
	connect(DeltaParameter, SIGNAL(Moved(float, float, float, float)), this, SLOT(UpdatePositionFrom2DControl(float, float, float, float)));
	connect(DeltaParameter, SIGNAL(FinishMoving()), this, SLOT(UpdateDeltaPositionFromLineEditValue()));
	
	connect(ui->leTerminal, SIGNAL(returnPressed()), this, SLOT(TerminalTransmit()));

	connect(DeltaPort, SIGNAL(FinishReadLine(QString)), this, SLOT(PrintReceiveData(QString)));
	connect(DeltaPort, SIGNAL(DeltaResponeReady()), this, SLOT(NoticeConnected()));
	connect(DeltaPort, SIGNAL(InHomePosition(float, float, float, float)), this, SLOT(UpdateGlobalHomePositionValueAndControlValue(float, float, float, float)));
	connect(DeltaPort, SIGNAL(ReceiveConvenyorPosition(float, float)), this, SLOT(UpdateConvenyorPosition(float, float)));
	connect(DeltaPort, SIGNAL(ReceiveConvenyorPosition(float, float)), DeltaImageProcesser->ConvenyorObjectManager, SLOT(UpdateNewPositionObjects(float, float)));

	connect(ui->pbAddGcode, SIGNAL(clicked(bool)), this, SLOT(AddGcodeLine()));
	connect(ui->cbGcode, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeGcodeParameter()));

	connect(ui->pbFormat, SIGNAL(clicked(bool)), this, SLOT(StandardFormatEditor()));

	connect(ui->pbFilter, SIGNAL(clicked(bool)), DeltaImageProcesser, SLOT(OpenParameterPanel()));
	connect(ui->pbLoadTestImage, SIGNAL(clicked(bool)), DeltaImageProcesser, SLOT(LoadTestImage()));
	connect(ui->pbLoadCamera, SIGNAL(clicked(bool)), DeltaImageProcesser, SLOT(LoadCamera()));
	connect(ui->pbObjectRect, SIGNAL(clicked(bool)), ui->lbScreenStreamer, SLOT(rectObject()));
	connect(ui->pbObjectLine, SIGNAL(clicked(bool)), ui->lbScreenStreamer, SLOT(lineObject()));
	connect(ui->pbObjectOrigin, SIGNAL(clicked(bool)), ui->lbScreenStreamer, SLOT(circleObject()));
	connect(ui->pbSelection, SIGNAL(clicked(bool)), ui->lbScreenStreamer, SLOT(selectProcessRegion()));
	connect(ui->pbSwitchWorkFlow, SIGNAL(clicked(bool)), DeltaImageProcesser, SLOT(SwitchLayer()));
	connect(ui->pbChangeXAxis, SIGNAL(clicked(bool)), DeltaImageProcesser, SLOT(changeAxisDirection()));
	connect(ui->pbClearDetectObjects, SIGNAL(clicked(bool)), DeltaImageProcesser->ConvenyorObjectManager, SLOT(RemoveAllDetectObjects()));

	connect(ui->leConvenyorSpeed, SIGNAL(textChanged(QString)), this, SLOT(SetConvenyorSpeed()));

	connect(ui->lbScreenStreamer, SIGNAL(FinishDrawObject(int, int, int, int)), DeltaImageProcesser, SLOT(GetObjectInfo(int, int, int, int)));
	connect(ui->lbScreenStreamer, SIGNAL(FinishMeasureSpace(int)), DeltaImageProcesser, SLOT(GetDistance(int)));
	connect(ui->lbScreenStreamer, SIGNAL(FinishSelectProcessRegion(QPoint, QPoint, QPoint, QPoint)), DeltaImageProcesser, SLOT(GetProcessRegion(QPoint, QPoint, QPoint, QPoint)));
	connect(ui->lbScreenStreamer, SIGNAL(FinishSelectCalibPoint(int, int)), DeltaImageProcesser, SLOT(GetCalibPoint(int, int)));

	connect(ui->actionBaudrate, SIGNAL(triggered()), this, SLOT(ConfigConnection()));
	connect(ui->actionGcode, SIGNAL(triggered()), this, SLOT(OpenGcodeReference()));
	connect(ui->actionExecute_All, SIGNAL(triggered()), this, SLOT(ExecuteSelectPrograms()));
	connect(ui->actionExecute, SIGNAL(triggered()), this, SLOT(ExecuteProgram()));
	connect(ui->pbGcodeReference, SIGNAL(clicked(bool)), this, SLOT(OpenGcodeReference()));

	connect(DeltaGcodeManager, SIGNAL(OutOfObjectVariable()), DeltaImageProcesser->ConvenyorObjectManager, SLOT(RemoveOldestObject()));
	connect(DeltaGcodeManager, SIGNAL(JustUpdateVariable(QList<GcodeVariable>)), this, SLOT(DisplayGcodeVariable(QList<GcodeVariable>)));
	connect(DeltaGcodeManager, SIGNAL(MoveToNewPosition(float, float, float, float)), this, SLOT(UpdatePositionControl(float, float, float, float)));

	connect(ui->cbEnoughGetConvenyorContinues, SIGNAL(clicked(bool)), this, SLOT(TurnEnoughConvenyorPositionGetting()));

	connect(DeltaImageProcesser->ConvenyorObjectManager, SIGNAL(NewUpdateObjectPosition(QString, float)), DeltaGcodeManager, SLOT(UpdateSystemVariable(QString, float)));

	connect(ui->pbOpenPicture, SIGNAL(clicked(bool)), DeltaDrawingExporter, SLOT(OpenImage()));
	connect(ui->pbPainting, SIGNAL(clicked(bool)), DeltaDrawingExporter, SLOT(ConvertToDrawingArea()));

	connect(ui->pbDrawLine, SIGNAL(clicked(bool)), ui->lbDrawingArea, SLOT(SelectLineTool()));
	connect(ui->pbDrawRectangle, SIGNAL(clicked(bool)), ui->lbDrawingArea, SLOT(SelectRectangleTool()));
	connect(ui->pbDrawCircle, SIGNAL(clicked(bool)), ui->lbDrawingArea, SLOT(SelectCircleTool()));
	connect(ui->pbDrawArc, SIGNAL(clicked(bool)), ui->lbDrawingArea, SLOT(SelectArcTool()));
	connect(ui->pbZoomIn, SIGNAL(clicked(bool)), ui->lbDrawingArea, SLOT(SelectZoomInTool()));
	connect(ui->pbZoomOut, SIGNAL(clicked(bool)), ui->lbDrawingArea, SLOT(SelectZoomOutTool()));
	connect(ui->pbCursor, SIGNAL(clicked(bool)), ui->lbDrawingArea, SLOT(SelectCursor()));

	connect(ui->pbExportDrawingGcodes, SIGNAL(clicked(bool)), ui->lbDrawingArea, SLOT(ExportGcodes()));

	connect(ui->twDeltaManager, SIGNAL(tabBarClicked(int)), this, SLOT(ChangeDeltaDashboard(int)));
	connect(ui->twDeltaManager, SIGNAL(currentChanged(int)), this, SLOT(SelectTrueTabName(int)));

	connect(ui->pbExportBlocklyToGcode, SIGNAL(clicked(bool)), this, SLOT(SelectCursor()));
}

void MainWindow::InitVariables()
{
    DeltaPort = new ConnectionManager();
	DeltaPort->SetBaudrate(115200);

	DeltaGcodeManager = new GcodeProgramManager(this, ui->saProgramFiles, ui->wgProgramContainer, ui->pteGcodeArea, ui->pbExecuteGcodes, DeltaPort, DeltaParameter);
	
	//DebugLB = ui->lbDebug;
	Debugs.push_back(ui->lbDebug);

	DeltaGcodeManager->LoadPrograms();
	
	DeltaParameter = new DeltaVisualizer(ui->t2D);
	DeltaParameter->setObjectName(QStringLiteral("wg2D"));
	DeltaParameter->setGeometry(QRect(50, 10, 300, 300));
	DeltaParameter->SetDivisionComboBox(ui->cbDivision);

	DeltaDrawingExporter = new DrawingExporter(this);
	DeltaDrawingExporter->SetDrawingParameterPointer(ui->lbImageForDrawing, ui->lbImageWidth, ui->lbImageHeight, ui->leHeightScale, ui->leWidthScale, ui->leSpace, ui->leDrawingThreshold, ui->hsDrawingThreshold, ui->cbDrawMethod, ui->cbConversionTool);
	DeltaDrawingExporter->SetDrawingAreaWidget(ui->lbDrawingArea);

	ui->lbDrawingArea->InitGrid();
	ui->lbDrawingArea->SetGcodeEditor(ui->pteGcodeArea);
	ui->lbDrawingArea->SetEffector(ui->cbDrawingEffector);

	EditorTimer = new QTimer(this);
	//connect(EditorTimer, SIGNAL(timeout()), this, SLOT(RunSmartEditor()));
	//EditorTimer->start(500);

	ConvenyorTimer = new QTimer(this);
	connect(ConvenyorTimer, SIGNAL(timeout()), this, SLOT(GetConvenyorPosition()));

	

	//EditorTimer->start(500);
	//------------ OpenGl Init ----------
	
	VisualArea = new GLWidget();
    QHBoxLayout *container = new QHBoxLayout;
    container->addWidget(VisualArea);
    ui->wgOpenGl->setLayout(container);

	//---------- OpenCV Init -------------    

	DeltaImageProcesser = new ImageProcesser(this);
	DeltaImageProcesser->SetResultScreenPointer(ui->lbScreenStreamer);
	DeltaImageProcesser->SetObjectScreenPointer(ui->lbTrackingObject);
	DeltaImageProcesser->SetFPSInputBox(ui->leFPS);
	DeltaImageProcesser->SetDetectParameterPointer(ui->leXRec, ui->leYRec, ui->leRealDistance, ui->leXCoordinate, ui->leYCoordinate);

	// ---------------- Delta X tab -----------------
	/*DeltaXDashboard* dashBoard = new DeltaXDashboard(ui, this);
	dashBoard->DeltaPort = DeltaPort;
	dashBoard->DeltaGcodeManager = DeltaGcodeManager;
	dashBoard->VisualArea = VisualArea;
	dashBoard->DeltaParameter = DeltaParameter;
	dashBoard->DeltaImageProcesser = DeltaImageProcesser;
	dashBoard->DeltaDrawingExporter = DeltaDrawingExporter;

	DeltaXDashboards.push_back(dashBoard);*/	

	//------------------Blockly---------------
//	QWebEngineView* wevBlockly = new QWebEngineView();
//	ui->wevBlockly->setUrl(QUrl(QStringLiteral("C:/Users/Admin/Downloads/blockly-master/blockly-master/demos/index.html")));
	//---------------------- Update ----------------------

	HttpManager = new QNetworkAccessManager(this);
	connect(HttpManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(FinishedRequest(QNetworkReply*)));

	QNetworkRequest request = QNetworkRequest(QUrl("http://imwi.space/admin/login.php"));
	request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
	QUrlQuery params;
	params.addQueryItem("user", "trungdoanhong");
	params.addQueryItem("pass", "doanhongtrung");
	HttpManager->post(request, params.query().toUtf8());
}

void MainWindow::FinishedRequest(QNetworkReply *reply)
{
	if (reply->error() != QNetworkReply::NoError)
	{


		return;
	}

	QString respondString = QString(reply->readAll());
	//QMessageBox::information(this, "response", respondString);

	if (respondString.indexOf(("ok")) > -1)
	{
		QNetworkRequest request = QNetworkRequest(QUrl("http://imwi.space/admin/server.php?software=DeltaXSoftware&info=version"));
		request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
		HttpManager->get(request);
	}
	else
	{
		QVersionNumber currentVersion = QVersionNumber::fromString(respondString);
		QVersionNumber appVersion = QVersionNumber::fromString(SoftwareVersion);
		int compare = QVersionNumber::compare(appVersion, currentVersion);
		/*switch (compare) {
		case -1:
			QMessageBox::information(this, "Version", "Have new version");

			break;
		case 0:
			QMessageBox::information(this, "Version", "Have no new version");
			break;
		case 1:
			QMessageBox::information(this, "Version", "Have old version");
			break;
		default:
			break;
		}*/

		if (compare == -1)
		{
			QMessageBox::StandardButton reply;
			reply = QMessageBox::question(this, "Have a new version of Delta X Software", "Do you want to update?",
				QMessageBox::Yes | QMessageBox::No);
			if (reply == QMessageBox::Yes) {
				QUrl myUrl("https://sourceforge.net/projects/delta-x-software/files/");
				QDesktopServices::openUrl(myUrl);
				QApplication::closeAllWindows();
				QApplication::quit();
			}			
		}
	}
}

void MainWindow::ExportBlocklyToGcode()
{
	/*QWebEnginePage* clone = new QWebEnginePage();
	
	ui->wevBlockly->page()->runJavaScript("document.getElementsByTagName(\"body\")[0].innerHTML = document.getElementById(\"content_javascript\").innerText");

	ui->wevBlockly->page()->toPlainText([this](const QString &result)
	{
		ui->pteGcodeArea->setText(result);
	});*/
}

void MainWindow::AddInstance(QList<MainWindow*>* deltaXMainWindows)
{
	if (deltaXMainWindows == NULL)
	{
		DeltaXMainWindows = new QList<MainWindow*>();
		DeltaXMainWindows->push_back(this);
	}
	else
	{
		DeltaXMainWindows = deltaXMainWindows;
		DeltaXMainWindows->push_back(this);
		initTabs();
	}

	
}

void MainWindow::ConnectDeltaRobot()
{
	if (ui->pbConnect->text() == "Connect" && !DeltaPort->IsConnect())
	{
		DeltaPort->FindDeltaRobot();			
	}

	else if (ui->pbConnect->text() == "Disconnect")
	{
		ui->pbConnect->setText("Connect");

		if (DeltaPort->IsConnect())
			DeltaPort->Disconnect();
	}
}

void MainWindow::RunSmartEditor()
{
	
}

void MainWindow::StandardFormatEditor()
{
	QString editorText = ui->pteGcodeArea->toPlainText();
	QList<QString> lines = editorText.split('\n');
	QList<QString> oldNumbers;
	QList<QString> newNumbers;
	QList<QString> oldGcodes;

	QString oldNumber = "";

	if (lines.size() > 100)
	{
		QMessageBox::information(this, "Warning", "Too many g-code lines ( > 100 ) will take time to format. You should divide the program into multiple files and use M98 F[filename] to execute each files.");
		return;
	}

	editorText = "";

	int i = 0;

	foreach(QString line, lines)
	{
		oldNumber = "";
		while (1)
		{
			if (line[0] == ' ')
			{
				line.replace(" ", "");
			}
			else
			{
				break;
			}
		}

		if (line[0] == 'N')
		{
			int spacePos = line.indexOf(' ');
			QString mS = line.mid(0, spacePos + 1);
			oldNumber = line.mid(1, spacePos);			
			
			line.replace(mS, "");			
		}

		while (1)
		{
			if (line[0] == ' ')
			{
				line.replace(" ", "");
			}
			else
			{
				break;
			}
		}

		if (line != "")
		{
			if (line[0] != ';')
			{
				QString numberS = QString("N") + QString::number(i);
				newNumbers.push_back(QString::number(i));
				oldNumbers.push_back(oldNumber);
				line = numberS + " " + line;
			}
		}

		editorText += line + "\n";
		i += 5;
	}

	int gotoCursor = 0;
	gotoCursor = editorText.indexOf("GOTO", gotoCursor);
	int gotoEnd = 0;

	while (gotoCursor > -1)
	{		
		//gotoEnd = editorText.indexOf("\n", gotoCursor);
		QString gotoIndexS = "";
		for (int i = 0; i < 20; i++)
		{
			QChar c = editorText.at(gotoCursor + 5 + i);
			if (c.isDigit())
				gotoIndexS += c;
			else
				break;
		}

		gotoCursor = editorText.indexOf("GOTO", gotoCursor + 5);

		for (int i = 0; i < oldNumbers.size(); i++)
		{
			if (oldNumbers.at(i).toInt() == gotoIndexS.toInt())
			{
				QString old = QString("GOTO ") + gotoIndexS;
				QString replace = QString("GOTO ") + newNumbers.at(i);
				editorText.replace(old, replace);
			}
		}
	}


	QTextCharFormat reset;
	ui->pteGcodeArea->setCurrentCharFormat(reset);

	ui->pteGcodeArea->setPlainText(editorText);

	ui->pteGcodeArea->currentCharFormat();

	QString htmlText = ui->pteGcodeArea->toHtml();
	//ui->pteGcodeArea->setHtml(htmlText.replace("font-weight:600", "font-weight:400"));

	if (ui->cbFormatColor->isChecked() == true)
	{
		QString htmlText = ui->pteGcodeArea->toHtml();

		htmlText = boldKey("G01", htmlText);
		htmlText = boldKey("G02", htmlText);
		htmlText = boldKey("G03", htmlText);
		htmlText = boldKey("G04", htmlText);
		htmlText = boldKey("G28", htmlText);
		htmlText = boldKey("M204", htmlText);
		htmlText = boldKey("M360", htmlText);
		htmlText = boldPlusKey("GOTO", "color:#ff5500;", htmlText);
		htmlText = boldPlusKey("IF", "color:#00aa00;", htmlText);
		htmlText = boldPlusKey("THEN", "color:#00aa00;", htmlText);
		htmlText = boldKey("M99", htmlText);
		htmlText = boldKey("M98", htmlText);
		htmlText = boldKey("M05", htmlText);
		htmlText = boldKey("M04", htmlText);
		htmlText = boldKey("M03", htmlText);

		htmlText = replaceHtmlSection(">;", 1, 200, "<", "<span style=\"font-style:italic;color:#00aa00;\">", "</span>", htmlText);
		htmlText = replaceHtmlSection(" O", 1, 50, "<", "<span style =\"font-weight:600;\">", "</span>", htmlText);
		htmlText = replaceHtmlSection("#", 0, 6, "&&&", "<span style=\"font-style:italic;\">", "</span>", htmlText);

		int beginKey = -1;
		int endKey = 0;

		ui->pteGcodeArea->setHtml(htmlText);
	}
	/*QList<QString> lines = htmlText.split('\n');

	foreach(QString line, lines)
	{
		int beginKey = line.indexOf("G01");
		int endKey = line.indexOf(" ", beginKey);
	}*/
}

void MainWindow::OpenGcodeReference()
{
	GcodeReference* gcodeReferenceWindow = new GcodeReference();
	gcodeReferenceWindow->show();
}

void MainWindow::ConfigConnection()
{
	bool ok;
	QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
		tr("Baudrate:"), QLineEdit::Normal,
		QString::number(DeltaPort->GetBaudrate()), &ok);
	if (ok && !text.isEmpty())
		DeltaPort->SetBaudrate(text.toInt());
}

void MainWindow::ChangeDeltaDashboard(int index)
{
	if (ui->twDeltaManager->count() == index + 1)
	{
		if (ID == 0)
		{
			if (DeltaXMainWindows == NULL)
			{
				DeltaXMainWindows = new QList<MainWindow*>();
				DeltaXMainWindows->push_back(this);
			}
		}

		MainWindow* mainWindow = new MainWindow();
		mainWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainWindow->ID = DeltaXMainWindows->size() - 1;
		mainWindow->Name = QString("Delta X ") + QString::number(mainWindow->ID + 2);

		QAction *actionNewDelta_X;
		actionNewDelta_X = new QAction(mainWindow);

		actionNewDelta_X->setCheckable(true);
		actionNewDelta_X->setChecked(true);
		actionNewDelta_X->setText(QString("Delta X ") + QString::number(mainWindow->ID + 2));
		DeltaXMainWindows->at(0)->ui->menuExecute->addAction(actionNewDelta_X);

		mainWindow->AddInstance(this->DeltaXMainWindows);
		mainWindow->ui->lbID->setText(QString("ID: ") + QString::number(mainWindow->ID + 1));
		mainWindow->SelectedAction = actionNewDelta_X;

		mainWindow->show();

		for (int i = 0; i < DeltaXMainWindows->size() - 1; i++)
		{
			DeltaXMainWindows->at(i)->ui->twDeltaManager->setTabText(index, QString("Delta") + QString::number(index + 1));
			QWidget *newDeltaTab = new QWidget();
			DeltaXMainWindows->at(i)->ui->twDeltaManager->addTab(newDeltaTab, QString());
			DeltaXMainWindows->at(i)->ui->twDeltaManager->setTabText(DeltaXMainWindows->at(i)->ui->twDeltaManager->indexOf(newDeltaTab), "+");
		}

		/*DeltaXDashboard* dashBoard = new DeltaXDashboard(ui, this);
		dashBoard->InitVariable();
		DeltaXDashboards.push_back(dashBoard);*/
	}
	else
	{
		DeltaXMainWindows->at(index)->setWindowFlags(Qt::WindowStaysOnTopHint);
		DeltaXMainWindows->at(index)->activateWindow();
		DeltaXMainWindows->at(index)->show();
		DeltaXMainWindows->at(index)->setFocus();
	}
	Debug(QString::number(index));
}

void MainWindow::SelectTrueTabName(int index)
{
	for (int i = 0; i < DeltaXMainWindows->size(); i++)
	{
		if (DeltaXMainWindows->at(i) != NULL)
		{
			if (DeltaXMainWindows->at(i)->ui != NULL)
			{
				if (DeltaXMainWindows->at(i)->ui->twDeltaManager != NULL)
				{
					DeltaXMainWindows->at(i)->ui->twDeltaManager->setCurrentIndex(i);
				}
			}
		}
	}
}

void MainWindow::AddNewProgram()
{
	DeltaGcodeManager->AddNewProgram();
}

void MainWindow::SaveProgram()
{
	DeltaGcodeManager->SaveGcodeIntoFile();
}

void MainWindow::ExecuteProgram()
{
	if (DeltaPort->IsConnect())
	{
		QPushButton* pbExe = qobject_cast<QPushButton*>(sender());

		if (pbExe->isChecked())
		{

		}
		else
		{
			DeltaGcodeManager->Stop();
			if (DeltaGcodeManager->InsideGcodeProgramManager != NULL)
			{
				DeltaGcodeManager->InsideGcodeProgramManager->Stop();
			}
			return;
		}

		QString exeGcodes = ui->pteGcodeArea->toPlainText();
		DeltaGcodeManager->ExecuteGcode(exeGcodes, true);
	}

	else
		Debug("Delta Robot is not connecting !");
}

void MainWindow::ExecuteSelectPrograms()
{
	QList<QAction*> actions = ui->menuExecute->actions();
	for (int i = 0; i < actions.size(); i++)
	{
		if (actions.at(i)->text().indexOf("Delta X") > -1)
		{
			QString actionName = actions.at(i)->text();
			if (actions.at(i)->isChecked() == true)
			{
				for (int j = 0; j < DeltaXMainWindows->size(); j++)
				{
					if (DeltaXMainWindows->at(j)->Name == actionName)
					{
						DeltaXMainWindows->at(j)->ui->pbExecuteGcodes->click();
					}
				}
			}
		}
	}
}

void MainWindow::ExecuteCurrentLine()
{
	if (ui->cbLockGcodeEditor->isChecked() == false)
	{
		return;
	}

	QTextCursor cursor;
	QString line;

	cursor = ui->pteGcodeArea->textCursor();
	cursor.movePosition(QTextCursor::StartOfBlock);
	cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
	line = cursor.selectedText();

	DeltaGcodeManager->ExecuteGcode(line);
}

void MainWindow::UpdateZLineEditValue(int z)
{
	ui->leZ->setText(QString::number(DeltaParameter->ZHome - z));

	if (ui->cbGcode->currentText() == "G01")
	{
		ui->leAg3->setText(QString::number(DeltaParameter->Z));
	}
}

void MainWindow::UpdateWLineEditValue(int w)
{
	ui->leW->setText(QString::number(w));

	if (ui->cbGcode->currentText() == "G01")
	{
		ui->leAg4->setText(QString::number(DeltaParameter->W));
	}
}

void MainWindow::UpdateDeltaPositionFromLineEditValue()
{
	DeltaParameter->X = ui->leX->text().toFloat();
	DeltaParameter->Y = ui->leY->text().toFloat();
	DeltaParameter->Z = ui->leZ->text().toFloat();
	DeltaParameter->W = ui->leW->text().toFloat();

	ui->vsZAdjsution->setValue(DeltaParameter->ZHome - DeltaParameter->Z);
	DeltaParameter->ChangeXY(ui->leX->text().toFloat(), ui->leY->text().toFloat());

	if (ui->cbGcode->currentText() == "G01")
	{
		ui->leAg1->setText(QString::number(DeltaParameter->X));
		ui->leAg2->setText(QString::number(DeltaParameter->Y));
		ui->leAg3->setText(QString::number(DeltaParameter->Z));
		ui->leAg4->setText(QString::number(DeltaParameter->W));
	}

	//DeltaGcodeManager->ExecuteGcode(QString("G01 X") + ui->leX->text() + QString(" Y") + ui->leY->text() + QString(" Z") + ui->leZ->text());
	DeltaPort->Send(QString("G01 X") + ui->leX->text() + QString(" Y") + ui->leY->text() + QString(" Z") + ui->leZ->text() + QString(" W") + ui->leW->text() + "\n");
}

void MainWindow::UpdatePositionFrom2DControl(float x, float y, float z, float w)
{
	ui->leX->setText(QString::number(x));
	ui->leY->setText(QString::number(y));
	ui->leZ->setText(QString::number(z));
	ui->leW->setText(QString::number(w));
}

void MainWindow::UpdatePositionControl(float x, float y, float z, float w)
{
	if (x == 0 && y == 0 && z == 0 && w == 0)
	{
		x = DeltaParameter->XHome;
		y = DeltaParameter->YHome;
		z = DeltaParameter->ZHome;
		w = DeltaParameter->WHome;
	}

	ui->leX->setText(QString::number(x));
	ui->leY->setText(QString::number(y));
	ui->leZ->setText(QString::number(z));
	ui->leW->setText(QString::number(w));

	DeltaParameter->X = x;
	DeltaParameter->Y = y;
	DeltaParameter->Z = z;
	DeltaParameter->W = w;

	ui->vsZAdjsution->setValue(DeltaParameter->ZHome - DeltaParameter->Z);
	DeltaParameter->ChangeXY(x, y);

	if (ui->cbGcode->currentText() == "G01")
	{
		ui->leAg1->setText(QString::number(DeltaParameter->X));
		ui->leAg2->setText(QString::number(DeltaParameter->Y));
		ui->leAg3->setText(QString::number(DeltaParameter->Z));
		ui->leAg4->setText(QString::number(DeltaParameter->W));
	}
}

void MainWindow::UpdateGlobalHomePositionValueAndControlValue(float x, float y, float z, float w)
{
	DeltaParameter->XHome = x;
	DeltaParameter->YHome = y;
	DeltaParameter->ZHome = z;
	DeltaParameter->WHome = w;

	UpdatePositionFrom2DControl(x, y, z, w);
	UpdateDeltaPositionFromLineEditValue();
}

void MainWindow::UpdateVelocity()
{
	DeltaPort->Send(QString("G01 F") + ui->leVelocity->text());
}

void MainWindow::UpdateAccel()
{
	DeltaPort->Send(QString("M204 A") + ui->leAccel->text());
}

void MainWindow::AdjustGripperAngle(int angle)
{
	DeltaPort->Send(QString("M360 E1"));
	DeltaPort->Send(QString("M03 S") + QString::number(angle * 5));
}

void MainWindow::Grip()
{
	DeltaPort->Send(QString("M360 E1"));
	if (ui->pbGrip->text() == "Grip")
	{
		ui->pbGrip->setText("Release");
		DeltaPort->Send(QString("M03 S") + ui->leGripperMax->text());
		ui->hsGripperAngle->setValue(ui->leGripperMax->text().toInt() / 5);
	}
	else
	{
		ui->pbGrip->setText("Grip");
		DeltaPort->Send(QString("M03 S") + ui->leGripperMin->text());
		ui->hsGripperAngle->setValue(ui->leGripperMin->text().toInt() / 5);
	}
}

void MainWindow::SetPump(bool value)
{
	DeltaPort->Send(QString("M360 E0"));
	if (value == true)
	{
		DeltaPort->Send(QString("M04"));
	}
	else
	{
		DeltaPort->Send(QString("M05"));
	}
}

void MainWindow::SetLaser(bool value)
{
	DeltaPort->Send(QString("M360 E3"));
	if (value == true)
	{
		DeltaPort->Send(QString("M04"));
	}
	else
	{
		DeltaPort->Send(QString("M05"));
	}
}

void MainWindow::Home()
{
	DeltaPort->Send("G28");

	ui->leX->setText(QString::number(DeltaParameter->XHome));
	ui->leY->setText(QString::number(DeltaParameter->YHome));
	ui->leZ->setText(QString::number(DeltaParameter->ZHome));
	ui->leW->setText(QString::number(DeltaParameter->WHome));

	DeltaParameter->X = DeltaParameter->XHome;
	DeltaParameter->Y = DeltaParameter->YHome;
	DeltaParameter->Z = DeltaParameter->ZHome;
	DeltaParameter->W = DeltaParameter->WHome;

	DeltaParameter->ChangeXY(0, 0);
	ui->vsZAdjsution->setValue(0);
}

void MainWindow::UpdateConvenyorPosition(float x, float y)
{
	ui->leCurrentConvenyoPosition->setText(QString::number(x));
}

void MainWindow::DisplayGcodeVariable(QList<GcodeVariable> gcodeVariables)
{
	for each (GcodeVariable var in gcodeVariables)
	{
		if (var.Name == ui->leVariable1->text())
		{
			ui->lbVar1->setText(QString::number(var.Value));
		}
		if (var.Name == ui->leVariable2->text())
		{
			ui->lbVar2->setText(QString::number(var.Value));
		}
		if (var.Name == ui->leVariable3->text())
		{
			ui->lbVar3->setText(QString::number(var.Value));
		}
		if (var.Name == ui->leVariable4->text())
		{
			ui->lbVar4->setText(QString::number(var.Value));
		}
		if (var.Name == ui->leVariable5->text())
		{
			ui->lbVar5->setText(QString::number(var.Value));
		}
		if (var.Name == ui->leVariable6->text())
		{
			ui->lbVar6->setText(QString::number(var.Value));
		}
	}
}

void MainWindow::SetConvenyorSpeed()
{
	//DeltaPort->Send(QString("M140 S") + ui->leConvenyorSpeed->text());

	//float interval = ui->leConvenPosInterval->text().toInt();
	float vel = ui->leConvenyorSpeed->text().toInt();

	if (ui->cbEnoughGetConvenyorContinues->isChecked() == false)
	{
		DeltaImageProcesser->SetConvenyorVelocity(vel);
	}
	else
	{

	}
	
	/*if (interval > 0 && vel > 0)
	{
		DeltaImageProcesser->ConvenyorObjectManager->SetApproximateValue(cv::Point3d((interval * vel) / 1000, 10, 10));
	}*/
}

void MainWindow::GetConvenyorPosition()
{
	DeltaPort->Send(QString("M701"));

	float interval = ui->leConvenPosInterval->text().toInt();
	float vel = ui->leConvenyorSpeed->text().toInt();
	/*if (interval > 0 && vel > 0)
	{
		DeltaImageProcesser->ConvenyorObjectManager->SetApproximateValue(cv::Point3d((interval * vel) / 1000, 10, 10));
	}*/
}

void MainWindow::TurnEnoughConvenyorPositionGetting()
{
	if (ui->cbEnoughGetConvenyorContinues->isChecked() == true)
	{
		ConvenyorTimer->start(ui->leConvenPosInterval->text().toInt());
		DeltaImageProcesser->CalculatedConvenyorTimer->stop();
	}
	else
	{
		ConvenyorTimer->stop();
		DeltaImageProcesser->CalculatedConvenyorTimer->start(100);
	}
}

void MainWindow::AddGcodeLine()
{
	QString gcodeName = ui->cbGcode->currentText();

	QString ag1 = ui->leAg1->text() != "" ? (QString(" ") + ui->lbAg1->text() + ui->leAg1->text()) : "";
	QString ag2 = ui->leAg2->text() != "" ? (QString(" ") + ui->lbAg2->text() + ui->leAg2->text()) : "";
	QString ag3 = ui->leAg3->text() != "" ? (QString(" ") + ui->lbAg3->text() + ui->leAg3->text()) : "";
	QString ag4 = ui->leAg4->text() != "" ? (QString(" ") + ui->lbAg4->text() + ui->leAg4->text()) : "";
	QString ag5 = ui->leAg5->text() != "" ? (QString(" ") + ui->lbAg5->text() + ui->leAg5->text()) : "";
	QString ag6 = ui->leAg6->text() != "" ? (QString(" ") + ui->lbAg6->text() + ui->leAg6->text()) : "";

	DeltaGcodeManager->AddGcodeLine(gcodeName + ag1 + ag2 + ag3 + ag4 + ag5 + ag6);
}

void MainWindow::ChangeGcodeParameter()
{
	QString gcodeName = ui->cbGcode->currentText();

	ui->lbAg1->setText("");
	ui->lbAg2->setText("");
	ui->lbAg3->setText("");
	ui->lbAg4->setText("");
	ui->lbAg5->setText("");
	ui->lbAg6->setText("");

	ui->leAg1->setText("");
	ui->leAg2->setText("");
	ui->leAg3->setText("");
	ui->leAg4->setText("");
	ui->leAg5->setText("");
	ui->leAg6->setText("");

	if (gcodeName == "G01")
	{
		ui->lbAg1->setText("X");
		ui->lbAg2->setText("Y");
		ui->lbAg3->setText("Z");
		ui->lbAg4->setText("W");
		ui->lbAg5->setText("F");

		ui->leAg1->setText(QString::number(DeltaParameter->X));
		ui->leAg2->setText(QString::number(DeltaParameter->Y));
		ui->leAg3->setText(QString::number(DeltaParameter->Z));
	}
	else if (gcodeName == "G02" || gcodeName == "G03")
	{
		ui->lbAg1->setText("F");
		ui->lbAg2->setText("I");
		ui->lbAg3->setText("J");
		ui->lbAg4->setText("X");
		ui->lbAg5->setText("Y");
	}
	else if (gcodeName == "G05")
	{
		ui->lbAg1->setText("I");
		ui->lbAg2->setText("J");
		ui->lbAg3->setText("P");
		ui->lbAg4->setText("Q");
		ui->lbAg5->setText("X");
		ui->lbAg6->setText("Y");
	}
	else if (gcodeName == "M03" || gcodeName == "M04")
	{
		ui->lbAg1->setText("S");
	}
	else if (gcodeName == "M204")
	{
		ui->lbAg1->setText("A");
	}
}

void MainWindow::ConnectConveyor()
{
	if (ui->pbConveyorConnect->text() == "Disconnect")
	{
		if (DeltaPort->ConveyorPort->isOpen())
		{
			DeltaPort->ConveyorPort->close();
		}

		ui->pbConveyorConnect->setText("Connect");
	}

	QStringList items;

	Q_FOREACH(QSerialPortInfo portInfo, QSerialPortInfo::availablePorts())
	{
		items << portInfo.portName();
		/*sP->setPortName(portName);
		sP->setBaudRate(baudrate);

		portList.push_back(sP);

		if (sP->open((QIODevice::ReadWrite)) == true)
		{
			connect(sP, SIGNAL(readyRead()), this, SLOT(ReadData()));

			QString name = sP->portName();

			sP->write("IsDelta\n");
			sP->write("IsDelta\n");
		}*/
	}

	bool ok;
	QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"), tr("COM Ports:"), items, 0, false, &ok);
	if (ok && !item.isEmpty())
	{
		bool ok2;
		QString baudrate = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Baudrate:"), QLineEdit::Normal, "115200", &ok2);
		if (ok2 && !baudrate.isEmpty())
		{
			DeltaPort->ConveyorPort = new QSerialPort();
			DeltaPort->ConveyorPort->setPortName(item);
			DeltaPort->ConveyorPort->setBaudRate(baudrate.toInt());
			if (DeltaPort->ConveyorPort->open((QIODevice::ReadWrite)) == true)
			{
				//QMessageBox::information(this, "Noti", "Connected");
				ui->pbConveyorConnect->setText("Disconnect");
			}
		};
	}
}

void MainWindow::SetConveyorMode(int mode)
{
	DeltaPort->ConveyorSend(QString("M310 ") + QString::number(mode));
}

void MainWindow::MoveConveyor()
{
	if (ui->cbConveyorValueType->currentIndex() == 0)
	{
		DeltaPort->ConveyorSend(QString("M311 ") + ui->leConveyorvMovingValue->text());
	}
	else
	{
		DeltaPort->ConveyorSend(QString("M312 ") + ui->leConveyorvMovingValue->text());
	}
}

void MainWindow::ConnectSliding()
{
	if (ui->pbSlidingConnect->text() == "Disconnect")
	{
		if (DeltaPort->SlidingPort->isOpen())
		{
			DeltaPort->SlidingPort->close();

			ui->pbSlidingConnect->setText("Connect");
		}
	}

	QStringList items;

	Q_FOREACH(QSerialPortInfo portInfo, QSerialPortInfo::availablePorts())
	{
		items << portInfo.portName();
		/*sP->setPortName(portName);
		sP->setBaudRate(baudrate);

		portList.push_back(sP);

		if (sP->open((QIODevice::ReadWrite)) == true)
		{
		connect(sP, SIGNAL(readyRead()), this, SLOT(ReadData()));

		QString name = sP->portName();

		sP->write("IsDelta\n");
		sP->write("IsDelta\n");
		}*/
	}

	bool ok;
	QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"), tr("COM Ports:"), items, 0, false, &ok);
	if (ok && !item.isEmpty())
	{
		bool ok2;
		QString baudrate = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Baudrate:"), QLineEdit::Normal, "115200", &ok2);
		if (ok2 && !baudrate.isEmpty())
		{
			DeltaPort->SlidingPort = new QSerialPort();
			DeltaPort->SlidingPort->setPortName(item);
			DeltaPort->SlidingPort->setBaudRate(baudrate.toInt());
			if (DeltaPort->SlidingPort->open((QIODevice::ReadWrite)) == true)
			{
				//QMessageBox::information(this, "Noti", "Connected");
				ui->pbSlidingConnect->setText("Disconnect");
			}
		};
	}
}

void MainWindow::GoHomeSliding()
{
	DeltaPort->SlidingSend("M323");
}

void MainWindow::DisableSliding()
{
	DeltaPort->SlidingSend("M320");
}

void MainWindow::SetSlidingSpeed()
{
	DeltaPort->SlidingSend(QString("M321") + ui->leSlidingSpeed->text());
}

void MainWindow::SetSlidingPosition()
{
	DeltaPort->SlidingSend(QString("M322") + ui->leSlidingPosition->text());
}

void MainWindow::TerminalTransmit()
{
	DeltaPort->Send(ui->leTerminal->text());
	ui->leTerminal->setText("");
}

void MainWindow::PrintReceiveData(QString msg)
{
	msg.replace("\n", "");
	Debug(msg);
}

void MainWindow::NoticeConnected()
{
	Debug(DeltaPort->GetNamePort());

	ui->pbConnect->setText("Disconnect");
}

QString MainWindow::boldKey(QString key, QString htmlText)
{
	int keyOrder = htmlText.indexOf(key);

	if (keyOrder > -1)
	{
		htmlText = htmlText.replace(key, QString("<span style = \" font-weight:600;\">") + key + "</span>");
	}

	return htmlText;
}

QString MainWindow::boldPlusKey(QString key, QString plus, QString htmlText)
{
	int keyOrder = htmlText.indexOf(key);

	if (keyOrder > -1)
	{
		htmlText = htmlText.replace(key, QString("<span style = \" font-weight:600;") + plus + "\">" + key + "</span>");
	}

	return htmlText;
}

QString MainWindow::italyKey(QString key, QString htmlText)
{
	int keyOrder = htmlText.indexOf(key);

	if (keyOrder > -1)
	{
		htmlText = htmlText.replace(key, QString("<span style=\" font - style:italic; \">") + key + "</span>");
	}

	return htmlText;
}

QString MainWindow::replaceHtmlSection(QString start, int offset, int maxlen, QString finish, QString beforeSection, QString afterSection, QString htmlText)
{
	int beginKey = -1;
	int endKey = 0;

	beginKey = htmlText.indexOf(start);

	while (beginKey > -1)
	{
		if (finish != "&&&")
		{
			endKey = htmlText.indexOf(finish, beginKey);
		}
		else
		{
			endKey = beginKey + 1;
			while (htmlText.at(endKey).isLetterOrNumber())
			{
				endKey++;
			}
		}

		QString cmtSentence = htmlText.mid(beginKey + offset, endKey - beginKey - offset);
		QString cmtSentenceAfter = beforeSection + cmtSentence + afterSection;
		if (cmtSentence.length() < maxlen)
			htmlText = htmlText.replace(cmtSentence, cmtSentenceAfter);
		int panOrder = htmlText.indexOf("</p>", beginKey + cmtSentenceAfter.length());
		beginKey = htmlText.indexOf(start, panOrder);
	}
	return htmlText;
}

void MainWindow::initTabs()
{
	ui->twDeltaManager->removeTab(1);

	ui->menuExecute->clear();

	delete ui->menuExecute;

	ui->menuEditor->addMenu(DeltaXMainWindows->at(0)->ui->menuExecute);

	for (int i = 1; i < DeltaXMainWindows->size(); i++)
	{
		QWidget *newDeltaTab = new QWidget();
		ui->twDeltaManager->addTab(newDeltaTab, QString());
		ui->twDeltaManager->setTabText(i, QString("Delta") + QString::number(i + 1));
	}

	QWidget *newDeltaTab = new QWidget();
	ui->twDeltaManager->addTab(newDeltaTab, QString());
	ui->twDeltaManager->setTabText(ui->twDeltaManager->indexOf(newDeltaTab), "+");
}

void MainWindow::hideExampleWidgets()
{
	ui->frExProgram->setVisible(false);
}

void MainWindow::interpolateCircle()
{
	float r = 120;
	int resolution = 120;
	float raMinAngle;
	int xO = 0;
	int yO = 0;
	int x;
	int y;
	float raAngle;
	QString gcode;

	raMinAngle = qDegreesToRadians(360.0f / resolution);

	for (int i = 0; i < resolution; i++)
	{
		raAngle = raMinAngle * i;
		x = xO + r * qCos(raAngle);
		y = yO + r * qSin(raAngle);
		gcode += QString("G01 X") + QString::number(x) + " Y" + QString::number(y) + "\n";
	}

	ui->pteGcodeArea->setPlainText(gcode);
}

void MainWindow::makeEffectExample()
{
	QCursor cursorTarget = QCursor(QPixmap("icon/Zoom In_16px.png"));
	ui->lbDrawingArea->setCursor(cursorTarget);
}


