#pragma once

#include "Shape.h"

class Triangular : public Shape {
	int b, h;

public:
	Triangular();
	Triangular(string sName, int iB, int iH);

	virtual float getArea() override;
};