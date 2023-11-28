#include "Oval.h"

Oval::Oval() {}
Oval::Oval(string sName, int iR1, int iR2) : Shape(sName), r1(iR1), r2(iR2) {}

float Oval::getArea() {
	return r1 * r2 * 3.14f;
}