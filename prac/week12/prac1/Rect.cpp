#include "Rect.h"

Rect::Rect() {}
Rect::Rect(string sName, int iW, int iH) : Shape(sName), w(iW), h(iH) {}

float Rect::getArea() {
	return w * h;
}