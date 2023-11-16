#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_BASEARRAY__
#define __INCLUDE_BASEARRAY__
#include "BaseArray.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class MyStack : protected BaseArray {
	int headPtr,
		tailPtr;
public:
	MyStack(int iCapacity = 100) : BaseArray(iCapacity), headPtr(0), tailPtr(0) {}
	
	void push(int iInput);
	int capacity();
	int length();
	int pop();

	bool empty();
};

#endif