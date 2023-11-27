#ifndef __SPREADSHEETSERVICE_H__
#define __SPREADSHEETSERVICE_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_VECTOR__
#define __INCLUDE_VECTOR__
#include <vector>
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "../MyLogger/Logger.h"
#endif

#pragma comment(lib, "../x64/Debug/MyLogger.lib")

#ifndef __INCLUDE_SPREADSHEETPROG__
#define __INCLUDE_SPREADSHEETPROG__
#include "../MySpreadSheet/SpreadSheetProgram.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

namespace {
	class SpreadSheetService {
		Logger* _log;

		SpreadSheetProgram* prog;
	public:
		SpreadSheetService();
		~SpreadSheetService();



		void CreatWorkBookByExistingTablesService(map<string, vector<vector<string>>> pTabs, string pFn = "NewFile");
		void ShowWorkBookInfoService(string pFn);
	};

	SpreadSheetService::SpreadSheetService() {
		_log = new Logger("SpreadSheetService");
		_log->info("SpreadSheetService is allocated");

		prog = new SpreadSheetProgram();
	}

	SpreadSheetService::~SpreadSheetService() {
		_log->info("SpreadSheetService is deallocated");
		delete _log;

		delete prog;
	}

	void SpreadSheetService::CreatWorkBookByExistingTablesService(map<string, vector<vector<string>>> pTabs, string pFn) {
		prog->createWorkBookByExistingTables(pTabs, pFn);
	}

	void SpreadSheetService::ShowWorkBookInfoService(string pFn) {
		WorkBook*& wb = prog->getWorkBookByFileName(pFn);
		wb->showWorkbookInfo();
		cout << "\n";
		for (int i = 0; i < wb->getPageCnt(); ++i) {
			wb->getWorkPageByIdx(i)->showPage();
		}
	}
}

#endif