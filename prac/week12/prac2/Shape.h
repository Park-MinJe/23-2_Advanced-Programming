#pragma once

#include <string>
using namespace std;

class Shape {
protected:
	Shape* next;

public:
	Shape();

	void setNext(Shape* oNext);
	Shape*& getNext();

	virtual string toString() = 0;
};