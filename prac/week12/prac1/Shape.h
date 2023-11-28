#pragma once

#include <string>
using namespace std;

class Shape {
	string name;

public:
	Shape();
	Shape(string sName);

	string getName();
	virtual float getArea() = 0;
};