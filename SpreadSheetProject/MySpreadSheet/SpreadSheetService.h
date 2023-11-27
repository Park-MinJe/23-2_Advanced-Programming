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

		/*
		* CREATE
		*/
		void CreatWorkBookByExistingTablesService(map<string, vector<vector<string>>> pTabs, string pFn = "NewFile");

		/*
		* GET DATA OR LIST
		*/
		map<string, string> GetWorkBookList();
		pair<string, vector<string>> GetWorkBookListService(string pFn);
		map<string, vector<vector<string>>> GetWorkBookInfoService(string pFn);

		/*
		* SHOW DATA OR LIST AT CONSOLE
		*/
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

	/*
	* SHOW DATA OR LIST
	* <id, file name>
	*/
	map<string, string> SpreadSheetService::GetWorkBookList() {
		return prog->getWorkBookListByMap();
	}

	pair<string, vector<string>> SpreadSheetService::GetWorkBookListService(string pFn) {
		pair<string, vector<string>> rt;

		WorkBook*& wb = prog->getWorkBookByFileName(pFn);
		rt = wb->getWorkbookInfo();

		return rt;
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