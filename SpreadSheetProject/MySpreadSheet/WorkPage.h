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

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class WorkPage {
	string pageName;
	int rowSize, colSize;
	vector<vector<Cell*>> cells;
public:
	WorkPage(string name = "NewPage", int iRowSize = 100, int iColSize = 100)
		: pageName(name), rowSize(iRowSize), colSize(iColSize) {
		cells.resize(iRowSize);
		for (int i = 0; i < iRowSize; ++i) {
			cells[i].resize(iColSize);
			for (int j = 0; j < iColSize; ++j) {
				cells[i][j] = new Cell(i, j);
			}
		}
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
};

#endif