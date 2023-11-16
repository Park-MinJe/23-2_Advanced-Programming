#ifndef __BASEARRAY_H__
#define __BASEARRAY_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream> #endif
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class BaseArray {
	int maxLen;
	int* arr;
protected:BaseArray(int iLen);
		 ~BaseArray();
		 int getMaxLen();
		 void putElement(int iPtr, int iN);
		 int getNumByIdx(int iPtr);
};
#endif