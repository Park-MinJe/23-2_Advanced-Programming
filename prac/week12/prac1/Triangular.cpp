#include "Triangular.h"

Triangular::Triangular() {}
Triangular::Triangular(string sName, int iB, int iH) : Shape(sName), b(iB), h(iH) {}

float Triangular::getArea() {
	return 0.5f * b * h;
}