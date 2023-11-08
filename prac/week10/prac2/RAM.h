#ifndef __RAM_H__
#define __RAM_H__

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

class RAM : public BaseMemory {
public:
	RAM(int iSize) : BaseMemory(iSize){ }
	
	void writeRAM(const char* word) {
		write(word);
	}
	const char* readRAM() {
		return read();
	}
};

#endif