#pragma once

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle();
	virtual string toString() override;
};