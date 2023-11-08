#include "MyQueue.h"

MyQueue::MyQueue(int iLen)
	: BaseArray(iLen), headPtr(0), tailPtr(0) { }
MyQueue::~MyQueue() { }

void MyQueue::enqueue(int iN) {
	putElement(++tailPtr, iN);
}
int MyQueue::dequeue() {
	return getNumByIdx(++headPtr);
}

int MyQueue::capacity() {
	return getMaxLen();
}
int MyQueue::lenght() {
	return tailPtr - headPtr;
}