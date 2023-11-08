#include "BaseArray.h"

BaseArray::BaseArray(int iLen)
	: maxLen(iLen)
{
	arr = new int[iLen + 1];
}
BaseArray::~BaseArray() {
	delete[] arr;
}

int BaseArray::getMaxLen() {
	return maxLen;
}
void BaseArray::putElement(int iPtr, int iN) {
	arr[iPtr] = iN;
}
int BaseArray::getNumByIdx(int iPtr) {
	return arr[iPtr];
}