#ifndef PLUGINMAIN_H
#define PLUGINMAIN_H

#include <QtWidgets/QWidget>
#include <QTabwidget>
#include <vector>
#include "ui_pluginmain.h"

class PlugInMain : public QWidget
{
	Q_OBJECT

public:
	PlugInMain(QWidget *parent = 0);
	~PlugInMain();

	void init();
	QWidget *loadPlugins(QString pluginFileName, QWidget *parent);

private:
	Ui::PlugInMainClass ui;
	QTabWidget * tab_widget_;
	std::vector<QWidget*> widgets_;

};

#endif // PLUGINMAIN_H
