#ifndef __CELL_H__
#define __CELL_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_TYPES_H__
#define __INCLUDE_TYPES_H__
#include "Types.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class Node {
	int colIdx, rowIdx;
public:
	Node(int iCol = -1, int iRow = -1) : colIdx(iCol), rowIdx(iRow) { }

	void setColIdx(int iCol) { colIdx = iCol; }
	void setRowIdx(int iRow) { rowIdx = iRow; }
	void setColRowIdx(int iCol, int iRow) { colIdx = iCol; rowIdx = iRow; }

	int getColIdx() { return colIdx; }
	int getrowIdx() { return rowIdx; }
};

class Cell : public Node{
	Types* type;
	string value;
public:
	Cell(int iCol, int iRow)
		: Node(iCol, iRow) {
		type = new Types(TypeCode::TypeCode::NOTDEFINED);
		value = "";
	}
	~Cell() {
		delete type;
	}

	void setType(TypeCode::TypeCode type) {
		(this->type)->setType(type);
	}
	void setValue(string value) {
		this->value = value;
	}

	const Types*& getType() {
		return type;
	}
	const string getValue() {
		return value;
	}
};

#endif