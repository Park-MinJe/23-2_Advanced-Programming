#include <iostream>
#include <string>

using namespace std;

class Car {
	int speed;
	int gear;
	string color;
	int id;
public:
	static int numberOfCars;
	Car(int iSpeed = 0, int iGear = 1, string sColor = "white")
		: speed(iSpeed), gear(iGear), color(sColor)
	{
		numberOfCars++;
		id = numberOfCars;
	}
	static int getNumberOfCars() {
		return numberOfCars;
	}
};

int Car::numberOfCars = 0;

int main() {
	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	int n = Car::getNumberOfCars();
	cout << "지금까지 생성된 자동차 수 = " << n << endl;
	return 0;
}