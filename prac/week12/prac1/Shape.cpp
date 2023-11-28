#include "Shape.h"

Shape::Shape() {}
Shape::Shape(string sName) : name(sName) {}

string Shape::getName() {
	return name;
}