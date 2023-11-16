#ifndef __INKJETPRINTER_H__
#define __INKJETPRINTER_H__

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

class InkJetPrinter : protected Printer {
	int availableInk;
public:
	InkJetPrinter(string sModel, string sManufacturer, int iAvailableCnt, int iAvailableInk)
		: Printer(sModel, sManufacturer, iAvailableCnt), availableInk(iAvailableInk){ }
	void printInkJet(int pages) {
		if (print(pages)) {
			if (availableInk >= pages) {
				availableInk -= pages;
				cout << "����Ʈ �Ͽ����ϴ�.\n";
			}
			else {
				cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�.\n";
			}
		}
		else {
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�.\n";
		}
		
	}
	string inkJetToString() {
		return printerToString() + "\t,���� ��ũ " + to_string(availableInk);
	}
};

#endif