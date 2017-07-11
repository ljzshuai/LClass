#include "plugindemo.h"
#include <qlabel.h>
#include <qgridlayout.h>
#include <qdatetime.h>
#include <qpushbutton.h>

PlugInDemo::PlugInDemo(QWidget *parent)
	: QWidget(parent)
{
	this->resize(500, 600);
	QGridLayout *grid_lay = new QGridLayout(this);
	label_time_ = new QLabel(this);
	grid_lay->addWidget(label_time_);

	QObject::connect(&timer_, &QTimer::timeout, this, &PlugInDemo::timerOut);
	timer_.start(1000);
	this->setWindowTitle(QString::fromLocal8Bit("Ê±¼ä"));
}

void PlugInDemo::timerOut()
{
	QDateTime time = QDateTime::currentDateTime();
	QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
	label_time_->setText(str);
	timer_.start(1000);
}

PlugInDemo::~PlugInDemo()
{

}
