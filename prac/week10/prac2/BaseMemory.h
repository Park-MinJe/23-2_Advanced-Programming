#ifndef __BASEMEMORY_H__
#define __BASEMEMORY_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif
#ifndef __INCLUDE_CSTRING__
#define __INCLUDE_CSTRING__
#include <cstring>
#endif
#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class BaseMemory {
	int size;
	char* mem;
protected:
	BaseMemory(int iSize) : size(iSize) { mem = new char[size]; }
	~BaseMemory() { delete[] mem; }

	void write(const char* word) {
		strcpy_s(mem, size, word);
	}
	const char* read() {
		return mem;
	}
	int getSize() {
		return size;
	}
};

#endif