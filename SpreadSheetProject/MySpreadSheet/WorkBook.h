#ifndef __WORKBOOK_H__
#define __WORKBOOK_H__

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

#ifndef __INCLUDE_WORKPAGE__
#define __INCLUDE_WORKPAGE__
#include "WorkPage.h"
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "Logger.h"
#endif

#ifndef __INCLUDE_PRINTTABLE__
#define __INCLUDE_PRINTTABLE__
#include "PrintTable.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class WorkBook {
	Logger* _log;

	string fileName;
	int pageCnt;
	map<string, WorkPage*> pages;
	map<string, WorkPage*>::iterator iter;
public:
	WorkBook(string fn = "NewFile") : fileName(fn) {
		_log = new Logger("WorkBook-" + fileName);

		pageCnt = 1;
		WorkPage* tmp = new WorkPage();
		pages.insert(make_pair(tmp->getPageName(), tmp));

		_log->info("New workbook named \"" + fn + "\" is generated");
	}
	WorkBook(map<string, vector<vector<string>>> tabs, string fn = "NewFile") : fileName(fn) {
		_log = new Logger("WorkBook-" + fileName);

		pageCnt = tabs.size();
		map<string, vector<vector<string>>>::iterator tabsIter;
		for (tabsIter = tabs.begin(); tabsIter != tabs.end(); tabsIter++) {
			WorkPage* tmp = new WorkPage(*tabsIter);
			pages.insert(make_pair(tmp->getPageName(), tmp));
		}

		_log->info("New workbook named \"" + fn + "\" is generated");
	}

	~WorkBook() {
		for (iter = pages.begin(); iter != pages.end(); iter++) {
			if(iter->second)
				delete iter->second;
		}

		_log->debug("Workbook " + fileName + " is deallocated");
		if (_log)
			delete _log;
	}

	void setFileName(string fn) {
		fileName = fn;
	}
	string getFileName() {
		return fileName;
	}

	int getPageCnt() {
		return pageCnt;
	}

	WorkPage*& getWorkPageByIdx(int idx) {
		if (!isEmpty()) {
			iter = pages.begin();
			advance(iter, idx);
			return iter->second;
		}
		// TODO: return exception when workbook is empty
	}
	WorkPage*& getWorkPageByName(string name) {
		if (!isEmpty()) {
			iter = pages.find(name);
			return iter->second;
		}
		// TODO: return exception when workbook is empty
	}
	void creatNewPage(string name = "NewPage", int iRowSize = 100, int iColSize = 100) {
		pageCnt++;

		if (!pages.empty()) {
			int pageNameCnt = pages.count(name);
			if (pageNameCnt > 0) {
				string newPageName = name + "(" + to_string(pageNameCnt) + ")";
				_log->warn("There is page named " + name + ". System Changed new page name " + newPageName);
				name = newPageName;
			}
		}
		pages.insert(make_pair(name, new WorkPage(name, iRowSize, iColSize)));
	}
	void createNewPageWithExistingPage(pair<string, vector<vector<string>>> tab) {

	}

	bool isEmpty() {
		return pageCnt == 0;
	}

	const string toString() {
		stringstream ss;
		ss << hex << this;

		return string("WORKBOOK-" + fileName + "@") + ss.str();
	}

	vector<string>& getPageNames() {
		vector<string> rt;
		for (iter = pages.begin(); iter != pages.end(); iter++) {
			rt.push_back(iter->first);
		}

		return rt;
	}

	void showWorkbookInfo() {
		vector<string> rt;
		int i = 0;
		for (iter = pages.begin(); iter != pages.end(); iter++) {
			rt.push_back(iter->second->toString());
			++i;
		}
		printTable("Pages at " + this->toString(), rt);
	}
};

#endif