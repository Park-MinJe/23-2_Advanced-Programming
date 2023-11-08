#ifndef __ROM_H__
#define __ROM_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif
#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif
#ifndef __INCLUDE_BASEMEMORY_H__
#define __INCLUDE_BASEMEMORY_H__
#include "BaseMemory.h"
#endif

class ROM : public BaseMemory {
public:
	ROM(int iSize, const char* cWord) :BaseMemory(iSize) { 
		write(cWord);
	}

	const char* readROM() {
		return read();
	}
	int getROMSize() {
		return getSize();
	}
};

#endif