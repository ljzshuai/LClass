#include "plugindemo.h"

#include <QtCore/QtPlugin>
#include "plugindemoplugin.h"


PlugInDemoPlugin::PlugInDemoPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void PlugInDemoPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool PlugInDemoPlugin::isInitialized() const
{
	return initialized;
}

QWidget *PlugInDemoPlugin::createWidget(QWidget *parent)
{
	return new PlugInDemo(parent);
}

QString PlugInDemoPlugin::name() const
{
	return "PlugInDemo";
}

QString PlugInDemoPlugin::group() const
{
	return "My Plugins";
}

QIcon PlugInDemoPlugin::icon() const
{
	return QIcon();
}

QString PlugInDemoPlugin::toolTip() const
{
	return QString();
}

QString PlugInDemoPlugin::whatsThis() const
{
	return QString();
}

bool PlugInDemoPlugin::isContainer() const
{
	return false;
}

QString PlugInDemoPlugin::domXml() const
{
	return "<widget class=\"PlugInDemo\" name=\"plugInDemo\">\n"
		" <property name=\"geometry\">\n"
		"  <rect>\n"
		"   <x>0</x>\n"
		"   <y>0</y>\n"
		"   <width>100</width>\n"
		"   <height>100</height>\n"
		"  </rect>\n"
		" </property>\n"
		"</widget>\n";
}

QString PlugInDemoPlugin::includeFile() const
{
	return "plugindemo.h";
}

