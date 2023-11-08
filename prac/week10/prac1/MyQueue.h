#ifndef __MY_QUEUE_H__
#define __MY_QUEUE_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif
#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif
#ifndef __INCLUDE_BASEARRAY_H__
#define __INCLUDE_BASEARRAY_H__
#include "BaseArray.h"
#endif

class MyQueue : public BaseArray {
	int headPtr,
		tailPtr;
public:
	MyQueue(int iLen = 100);
	~MyQueue();

	void enqueue(int iN);
	int dequeue();

	int capacity();
	int lenght();
};

#endif