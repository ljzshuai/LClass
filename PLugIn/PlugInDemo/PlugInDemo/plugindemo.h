#ifndef PLUGINDEMO_H
#define PLUGINDEMO_H

#include <QtWidgets/QWidget>
#include <qtimer.h>
class QLabel;
class PlugInDemo : public QWidget
{
	Q_OBJECT

public:
	PlugInDemo(QWidget *parent = 0);
	~PlugInDemo();

	void timerOut();
private:
	QTimer timer_;
	QLabel * label_time_;
};

#endif // PLUGINDEMO_H
