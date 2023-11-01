#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
	int id;
	string name;
	int mark;

	static int objCnt;

public:
	Car(){}
	Car(int iId, string sName, int iMark);
	void printCarInfo();
	static int getObjCnt() {
		return objCnt;
	}
};

#endif