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

#ifndef __INCLUDE_VECTOR__
#define __INCLUDE_VECTOR__
#include <vector>
#endif

#ifndef __INCLUDE_WORKPAGE__
#define __INCLUDE_WORKPAGE__
#include "WorkPage.h"
#endif

class WorkBook {
	string fileName;
	int pageCnt;
	vector<WorkPage*> pages;
public:
	WorkBook(string fn = "NewFile") : fileName(fn) {
		pageCnt = 1;
		pages.reserve(pageCnt);
		pages.push_back(new WorkPage());
	}
	~WorkBook() {
		for (int i = 0; i < pageCnt; ++i) {
			delete pages.at(i);
		}
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
		if (!isEmpty())
			return pages.at(idx);
		// TODO: return exception when workbook is empty
	}
	void creatNewPage(string name = "NewPage", int iRowSize = 100, int iColSize = 100) {
		pageCnt++;
		pages.reserve(pageCnt);
		pages.push_back(new WorkPage(name, iRowSize, iColSize));
	}

	bool isEmpty() {
		return pageCnt == 0;
	}

	const string toString() {
		stringstream ss;
		ss << hex << this;

		return string("WORKBOOK@") + ss.str();
	}

	string*& getPageNames() {
		string* rt = new string[pageCnt];
		for (int i = 0; i < pageCnt; ++i) {
			rt[i] = pages.at(i)->getPageName();
		}

		return rt;
	}
};

#endif