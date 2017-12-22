#include "lexcel.h"
#include <QtWidgets/QApplication>
#include "lexcel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LJZ::LExcel* w1 = LJZ::LExcel::instance();
	LJZ::LExcel* w2 = LJZ::LExcel::instance();

	w1->setValue(2, 2, "这是(2,2)");
	w1->saveAs("D:\\w1.xlsx");

	w2->setValue(2, 2, "这是(2,2)");
	w2->saveAs("D:\\w2.xlsx");

	delete w1;
	delete w2;
	return a.exec();
}
