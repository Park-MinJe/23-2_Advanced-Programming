#pragma once

#include "Shape.h"

class Circle : public Shape {
public:
	Circle();
	virtual string toString() override;
};