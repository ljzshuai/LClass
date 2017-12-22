#include "lexcel.h"
#include <qregexp.h>
namespace LJZ{

	LExcel::LExcel()
		:_new_excel(true)
	{
		_excel = new QAxObject("Excel.Application");
		_work_books = _excel->querySubObject("WorkBooks");
		_work_books->dynamicCall("ADD");
		_work_book = _excel->querySubObject("ActiveWorkBook");
		_work_sheets = _work_book->querySubObject("sheets");
		_work_sheet = _work_sheets->querySubObject("Item(int)", 1);
	}

	LExcel::LExcel(const QString& filePath)
		:_new_excel(false)
	{
		
	}

	LExcel* LExcel::instance()
	{
		return new LExcel();
	}

	LExcel* LExcel::instance(const QString& filePath)
	{
		return new LExcel(filePath);
	}

	bool LExcel::saveAs(const QString& path)
	{
		if (!_work_book)
			return false;

		//QRegExp rx("");
		//if (!rx.exactMatch(path))
		//	return false;

		_work_book->dynamicCall("SaveAs(const QString&)", path);
		return true;
	}

	bool LExcel::setValue(UInt row, UInt column, const QString& value)
	{
		auto cell = _work_sheet->querySubObject("Cells(int,int)", row, column);
		return cell->setProperty("Value", value);
	}

	LExcel::~LExcel()
	{
		_work_book->dynamicCall("close");
		_work_sheet->clear();
		_excel->dynamicCall("Quit(void)");
	}
}