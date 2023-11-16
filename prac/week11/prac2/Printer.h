#ifndef __PRINTER_H__
#define __PRINTER_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class Printer {
	string model,
		manufacturer;
	int printedCount,
		availableCount;
protected:
	Printer(string sModel, string sManufacturer, int iAvailableCnt)
		: model(sModel), manufacturer(sManufacturer), printedCount(0), availableCount(iAvailableCnt){}
	bool print(int pages) {
		if (availableCount >= pages) {
			printedCount += pages;
			availableCount -= pages;
			return true;
		}
		else {
			return false;
		}
	}
	string printerToString() {
		return model + "\t," + manufacturer + "\t,남은 종이 " + to_string(availableCount) + "장";
	}
};

#endif