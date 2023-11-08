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
	Types* typeWithValue;
public:
	Cell(int iCol, int iRow, TypeCode::TypeCode tc = TypeCode::NUMBER, double value);
};

#endif