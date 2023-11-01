#include "Car.h"

int Car::objCnt = 0;

int main() {
	int carNum = 0, carIdTmp, carMarkTmp;
	string carNameTmp;

	cout << "How many vehicles are you entering(1 - 10)?";
	cin >> carNum;
	Car** carArr = new Car*[carNum];

	for (int i = 0; i < carNum; i++) {
		cout << "\nInput Car Id: ";
		cin >> carIdTmp;
		cout << "Input Car Name: ";
		cin >> carNameTmp;
		cout << "Input Car Mark(1 - 10): ";
		cin >> carMarkTmp;

		carArr[i] = new Car(carIdTmp, carNameTmp, carMarkTmp);

		cout << "\n";
		carArr[i]->printCarInfo();
	}

	cout << "\tCar objects generated in main: " << Car::getObjCnt() << "\n";

	delete[] carArr;
}