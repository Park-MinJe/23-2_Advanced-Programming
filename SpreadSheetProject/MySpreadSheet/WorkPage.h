#ifndef __WORKPAGE_H__
#define __WORKPAGE_H__

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

#ifndef __INCLUDE_CELL__
#define __INCLUDE_CELL__
#include "Cell.h"
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "../MyLogger/Logger.h"
#include "../MyLogger/Logger.cpp"
#endif

#ifndef __INCLUDE_PRINTTABLE__
#define __INCLUDE_PRINTTABLE__
#include "PrintTable.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class WorkPage {
	Logger* _log;

	string pageName;
	int rowSize, colSize;
	vector<vector<Cell*>> cells;
public:
	WorkPage(string name = "NewPage", int iRowSize = 100, int iColSize = 100)
		: pageName(name), rowSize(iRowSize), colSize(iColSize) {
		_log = new Logger("WorkPage-" + pageName);
		_log->info("\"" + name + "\" is generated. Row size is " + to_string(iRowSize) + " and col size is " + to_string(iColSize));

		cells.resize(iRowSize);
		for (int i = 0; i < iRowSize; ++i) {
			cells[i].resize(iColSize);
			for (int j = 0; j < iColSize; ++j) {
				cells[i][j] = new Cell(i, j);
			}
		}
	}
	WorkPage(pair<string, vector<vector<string>>> tab)
		: pageName(tab.first), rowSize(tab.second.size()), colSize(tab.second.at(0).size())
	{
		_log = new Logger("WorkPage-" + pageName);
		_log->info("\"" + pageName + "\" is generated. Row size is " + to_string(rowSize) + " and col size is " + to_string(colSize));

		cells.resize(rowSize);
		for (int i = 0; i < rowSize; ++i) {
			cells[i].resize(colSize);
			for (int j = 0; j < colSize; ++j) {
				const string& s = tab.second.at(i).at(j);
				string::const_iterator it = s.begin();
				while (it != s.end() && std::isdigit(*it)) ++it;
				bool isNumberic = !s.empty() && it == s.end();

				if (isNumberic) {
					cells[i][j] = new Cell(i, j, s, TypeCode::TypeCode::NUMBER);
				}
				else {
					cells[i][j] = new Cell(i, j, s, TypeCode::TypeCode::TEXT);
				}
			}
		}
	}

	~WorkPage() {
		vector<vector<Cell*>>::iterator vectorCellIter;
		vector<Cell*>::iterator cellPtrIter;
		for (vectorCellIter = cells.begin(); vectorCellIter != cells.end(); vectorCellIter++) {
			for (cellPtrIter = (*vectorCellIter).begin(); cellPtrIter != (*vectorCellIter).end(); cellPtrIter++) {
				delete* cellPtrIter;
			}
		}

		_log->debug("Work page " + pageName + " is deallocated");
		delete _log;
	}

	void setPageName(string pn) {
		pageName = pn;
	}
	void setRowSize(int row) {
		rowSize = row;
	}
	void setColSize(int col) {
		colSize = col;
	}

	const string getPageName() {
		return pageName;
	}
	const int getRowSize() {
		return rowSize;
	}
	const int getColSize() {
		return colSize;
	}

	void setCellByIdx(int row, int col, string value, TypeCode::TypeCode tc = TypeCode::TypeCode::NOTDEFINED) {
		Cell*& target = cells.at(row).at(col);
		target->setType(tc);
		target->setValue(value);
	}
	Cell*& getCellByIdx(int row, int col) {
		return cells.at(row).at(col);
	}

	const string toString() {
		stringstream ss;
		ss << hex << this;

		return string("WORKPAGE-" + pageName + "@") + ss.str();
	}

	void showPage() {
		printTable(this->toString(), cells);
	}
};

#endif