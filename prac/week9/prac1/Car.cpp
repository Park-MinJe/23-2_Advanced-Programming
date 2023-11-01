#include "Car.h"

Car::Car(int iId, string sName, int iMark)
	: id(iId), name(sName), mark(iMark) {
	objCnt++;
}

void Car::printCarInfo() {
	cout << "Car ID: " << id << "\n";
	cout << "Car Name: " << name << "\n";
	cout << "Car Mark: " << mark << "\n";
}