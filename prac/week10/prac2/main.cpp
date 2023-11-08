#include "RAM.h"
#include "ROM.h"
#include <typeinfo>

#define WORD_SIZE 8

int main() {
	ROM myRom(WORD_SIZE, "Dongguk");

	int sizeOfRom = myRom.getROMSize();
	RAM myRam(sizeOfRom);
	myRam.writeRAM(myRom.readROM());
	cout << typeid(myRam).name() << endl;
	cout << myRam.readRAM() << endl;
}