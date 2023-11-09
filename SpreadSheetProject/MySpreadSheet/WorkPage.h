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
	vector<vector<Cell>> cells;
public:
	WorkPage() { }
	WorkPage(string name, int iRowSize = 100, int iColSize = 100)
		: pageName(name), rowSize(iRowSize), colSize(iColSize) { }
};

#endif