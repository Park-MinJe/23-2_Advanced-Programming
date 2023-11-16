#ifndef __LASERPRINTER_H__
#define __LASERPRINTER_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __INCLUDE_PRINTER__
#define __INCLUDE_PRINTER__
#include "Printer.h"
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

class LaserPrinter : protected Printer {
	int availableToner;
public:
	LaserPrinter(string sModel, string sManufacturer, int iAvailableCnt, int iAvailableToner)
		: Printer(sModel, sManufacturer, iAvailableCnt), availableToner(iAvailableToner) { }
	void printLaser(int pages) {
		if (print(pages)) {
			if (availableToner >= pages) {
				availableToner -= pages;
				cout << "프린트 하였습니다.\n";
			}
			else {
				cout << "토너가 부족하여 프린트 할 수 없습니다.\n";
			}
		}
		else {
			cout << "용지가 부족하여 프린트 할 수 없습니다.\n";
		}
		
	}
	string laserToString() {
		return printerToString() + "\t,남은 토너 " + to_string(availableToner);
	}
};

#endif