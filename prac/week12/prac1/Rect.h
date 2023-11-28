#pragma once

#include "Shape.h"

class Rect : public Shape {
	int w, h;

public:
	Rect();
	Rect(string sName, int iW, int iH);

	virtual float getArea() override;
};