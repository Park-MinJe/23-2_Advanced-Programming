#include "Shape.h"

Shape::Shape() :next(nullptr) {}

void Shape::setNext(Shape* oNext) {
	next = oNext;
}

Shape*& Shape::getNext() {
	return next;
}