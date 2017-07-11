#include "pluginmain.h"
#include <QtWidgets/QApplication>
#include <qdir.h>
#include <qdebug.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PlugInMain w;
	w.show();

	return a.exec();
}
