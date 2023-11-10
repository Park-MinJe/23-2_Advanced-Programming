#ifndef __TESTING_H__
#define __TESTING_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_TYPES__
#define __INCLUDE_TYPES__
#include "Types.h"
#endif

#ifndef __INCLUDE_CELL__
#define __INCLUDE_CELL__
#include "Cell.h"
#endif

#ifndef __INCLUDE_WORKPAGE__
#define __INCLUDE_WORKPAGE__
#include "WorkPage.h"
#endif

#ifndef __INCLUDE_WORKBOOK__
#define __INCLUDE_WORKBOOK__
#include "WorkBook.h"
#endif

#ifndef __INCLUDE_SPREADSHEETPROG__
#define __INCLUDE_SPREADSHEETPROG__
#include "SpreadSheetProgram.h"
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "Logger.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

Logger* _logTest = new Logger("Testing");

void _typeDownCasting() {
	Types* pInterface = new Integer(10);

	cout << ((Integer*)pInterface)->getIntValue() << "\n";

	delete pInterface;
}

void _workPageInitializing() {
	WorkPage* p = new WorkPage("test_page", 10, 10);
	
	p->setCellByIdx(3, 2, "10", TypeCode::TypeCode::INTEGER);
	cout << p->getCellByIdx(3, 2)->toString();

	delete p;
}

void _workBookInitializing() {
	WorkBook* wb = new WorkBook();

	int pageCnt = wb->getPageCnt();
	cout << wb->getWorkPageByIdx(0)->toString() << endl;
	wb->showWorkbookInfo();
	cout << "\n";

	wb->creatNewPage("CreatedPage");
	pageCnt = wb->getPageCnt();
	cout << wb->getWorkPageByIdx(pageCnt - 1)->toString() << endl;
	wb->showWorkbookInfo();

	delete wb;
}

void _spreadSheetProgram() {
	SpreadSheetProgram* prog = new SpreadSheetProgram();
	string workbookNames[2] = { "NewFile", "CreatedFile" };

	prog->createWorkBook(workbookNames[0]);
	WorkBook*& wb1 = prog->getWorkBookByFileName(workbookNames[0]);
	//wb1->showWorkbookInfo();
	prog->showFilesInfo();
	cout << "\n";

	prog->createWorkBook(workbookNames[1]);
	WorkBook*& wb2 = prog->getWorkBookByFileName(workbookNames[1]);
	//wb2->showWorkbookInfo();
	prog->showFilesInfo();

	delete prog;
}

#endif