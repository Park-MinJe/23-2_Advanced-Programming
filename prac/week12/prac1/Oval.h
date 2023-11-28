#pragma once

#include "Shape.h"

class Oval : public Shape {
	int r1, r2;

public:
	Oval();
	Oval(string sName, int iR1, int iR2);

	virtual float getArea() override;
};