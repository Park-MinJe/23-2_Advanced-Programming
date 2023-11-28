#pragma once

#include "Shape.h"

class Line : public Shape {
public:
	Line();
	virtual string toString() override;
};