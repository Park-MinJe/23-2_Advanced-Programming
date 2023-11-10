#ifndef __SPREAD_SHEET_PROG__
#define __SPREAD_SHEET_PROG__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_MAP__
#define __INCLUDE_MAP__
#include <map>
#endif

#ifndef __INCLUDE_WORKBOOK__
#define __INCLUDE_WORKBOOK__
#include "WorkBook.h"
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "Logger.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class SpreadSheetProgram {
	Logger* _log;

	map<string, WorkBook*> files;
	map<string, WorkBook*>::iterator iter;
public:
	SpreadSheetProgram() {
		_log = new Logger("SpreadSheetProgram");
		_log->info("My Spread Sheet Program is running");
	}
	~SpreadSheetProgram() {
		for (iter = files.begin(); iter != files.end(); iter++) {
			delete iter->second;
		}

		_log->debug("My Spread Sheet Program is stopped");
		delete _log;
	}

	void createWorkBook(string fn = "NewFile") {
		if (!files.empty()) {
			int fnCnt = files.count(fn);
			if (fnCnt > 0) {
				string newFn = fn + "(" + to_string(fnCnt) + ")";
				_log->warn("There is file named " + fn + ". System Changed new workbook name " + newFn);
				fn = newFn;
			}
		}

		files.insert(make_pair(fn, new WorkBook(fn)));
	}
	void createWorkBookByExistingFile() {

	}

	WorkBook*& getWorkBookByFileName(string fn) {
		if (!files.empty()) {
			iter = files.find(fn);
			/*if (iter == files.end()) {
				_log->warn("There is no workbook file named " + fn);
			}*/
		}
		else {
			_log->warn("There is no WorkBook file");
		}
		return iter->second;
	}

	void showFilesInfo() {
		for (iter = files.begin(); iter != files.end(); iter++) {
			iter->second->showWorkbookInfo();
		}
	}
};

#endif