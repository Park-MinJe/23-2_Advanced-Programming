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

#ifndef __INCLUDE_TYPEINFO__
#define __INCLUDE_TYPEINFO__
#include <typeinfo>
#endif

#ifndef __INCLUDE_SSTREAM__
#define __INCLUDE_SSTREAM__
#include <sstream>
#endif

#ifndef __INCLUDE_TYPES_H__
#define __INCLUDE_TYPES_H__
#include "Types.h"
#endif

#ifndef __INCLUDE_LOGGER__
#define __INCLUDE_LOGGER__
#include "Logger.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class Node {
	int colIdx, rowIdx;
public:
	Node(int iRow = -1, int iCol = -1) : colIdx(iCol), rowIdx(iRow) { }

	void setColIdx(int iCol) { colIdx = iCol; }
	void setRowIdx(int iRow) { rowIdx = iRow; }
	void setColRowIdx(int iCol, int iRow) { colIdx = iCol; rowIdx = iRow; }

	int getColIdx() { return colIdx; }
	int getrowIdx() { return rowIdx; }
};

class Cell : public Node{
	Logger* _log;

	Types* type;
	string value;
public:
	Cell(int iRow, int iCol, string sValue = "", TypeCode::TypeCode tc = TypeCode::TypeCode::NOTDEFINED)
		: Node(iRow, iCol) {
		_log = new Logger("CELL[" + to_string(getrowIdx()) + "," + to_string(getColIdx()) + "]");

		type = new Types(tc);
		value = sValue;
	}
	~Cell() {
		delete _log;
		delete type;
	}

	void setType(TypeCode::TypeCode tc) {
		type->setType(tc);
	}
	void setValue(string value) {
		this->value = value;
	}

	const Types* getType() {
		return type;
	}
	const string& getValue() {
		return value;
	}

	const string toString() {
		stringstream ss;
		ss << hex << this;

		return type->getTypeName() + string("@") + ss.str();
	}
};

#endif