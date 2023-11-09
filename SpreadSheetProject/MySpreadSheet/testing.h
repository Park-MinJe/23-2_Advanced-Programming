#ifndef __TESTING_H__
#define __TESTING_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_TYPES__
#define __INCLUDE_TYPES__
#include "Types.h"
#endif

#ifndef __INCLUDE_CELL__
#define __INCLUDE_CELL__
#include "Cell.h"
#endif

#ifndef __INCLUDE_WORKPAGE__
#define __INCLUDE_WORKPAGE__
#include "WorkPage.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

void _typeDownCasting() {
	Types* pInterface = new Integer(10);

	cout << ((Integer*)pInterface)->getIntValue() << "\n";

	delete pInterface;
}

void _workPageInitializing() {
	WorkPage* p = new WorkPage("test_page", 10, 10);
	
	p->setCellByIdx(3, 2, "10", TypeCode::TypeCode::INTEGER);
	cout << p->getCellByIdx(3, 2)->toString();

	delete p;
}

#endif