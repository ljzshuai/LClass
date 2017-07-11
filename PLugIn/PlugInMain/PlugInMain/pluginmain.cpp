#include "pluginmain.h"
#include <qdir.h>
#include <QPluginLoader>
#include <qstring.h>
#include <D:\qt\5.8\mingw53_32\include\QtDesigner\QDesignerCustomWidgetInterface>
PlugInMain::PlugInMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	tab_widget_ = new QTabWidget(this);
	ui.hlay->addWidget(tab_widget_);
	init();
}

void PlugInMain::init()
{
	QString DirPath = QApplication::applicationDirPath();
	DirPath = DirPath + "/plugIn";
	QDir dir(DirPath);
	QStringList infolist = dir.entryList(QDir::Files);
	for each(auto file in infolist)
	{
		if (-1 == file.indexOf(".dll", 0))
			continue;
		QString tmp = DirPath + '/' + file;
		QWidget * tmp_widget = loadPlugins(tmp, this);
		if (tmp_widget)
			tab_widget_->addTab(tmp_widget,tmp_widget->windowTitle());
	}
}

QWidget* PlugInMain::loadPlugins(QString pluginFileName, QWidget *parent)
{
	QPluginLoader loader(pluginFileName);

	bool b = loader.load();
	if (!b)
		return nullptr;

	QObject *plugin = loader.instance();
	if (plugin)
	{
		QDesignerCustomWidgetInterface *iCustomWidgetInterface = qobject_cast<QDesignerCustomWidgetInterface *>(plugin);
		if (iCustomWidgetInterface){
			QWidget *widget = iCustomWidgetInterface->createWidget(parent);
			return widget;
		}
	}

	return nullptr;
}

PlugInMain::~PlugInMain()
{

}
