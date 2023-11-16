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
				cout << "����Ʈ �Ͽ����ϴ�.\n";
			}
			else {
				cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�.\n";
			}
		}
		else {
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�.\n";
		}
		
	}
	string laserToString() {
		return printerToString() + "\t,���� ��� " + to_string(availableToner);
	}
};

#endif