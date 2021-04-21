#include "RobotWindow.h"
#include "MainWindow.h"
#include "qdesktopwidget.h"
#include <QApplication>
#include "AccountWindow.h"
#include <QtQuick3D/qquick3d.h>

#define NEW_WINDOW

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath("./");
	QApplication a(argc, argv);
    QSurfaceFormat::setDefaultFormat(QQuick3D::idealSurfaceFormat());

#ifdef NEW_WINDOW
    MainWindow w;
#else
    ProjectWindow w;
#endif
	w.show();		

	return a.exec();
}
