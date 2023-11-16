#include "MyStack.h"

void MyStack::push(int iInput) {
	putElement(++tailPtr, iInput);
}
int MyStack::capacity() {
	return getMaxLen();
}
int MyStack::length() {
	return tailPtr - headPtr;
}
int MyStack::pop() {
	if(!empty())
		return getNumByIdx(tailPtr--);
}
bool MyStack::empty() {
	return tailPtr == headPtr;
}