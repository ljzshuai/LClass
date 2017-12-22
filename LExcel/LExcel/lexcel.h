#ifndef LEXCEL_H
#define LEXCEL_H
#include <qstring.h>
#include <qaxobject.h>
#include <stdint.h>
namespace LJZ{
	using UInt = uint64_t;
	class LExcel
	{
	public:
		static LExcel* instance();
		static LExcel* instance(const QString& filePath);
		bool saveAs(const QString&);
		bool setValue(UInt row, UInt column,const QString& value);
		~LExcel();
	private:
		LExcel();
		LExcel(const QString&filePath);

		QAxObject* _excel;
		QAxObject* _work_books;
		QAxObject* _work_book;
		QAxObject* _work_sheets;
		QAxObject* _work_sheet;

		bool _new_excel;
	};
}
#endif // LEXCEL_H
