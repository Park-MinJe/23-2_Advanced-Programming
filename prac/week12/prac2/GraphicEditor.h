#pragma once

#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "UI.h"

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor();

	void start();

	void insert(Shape* oInsert);
	void deleteByIdx(int iIdx);
	void showAll();
};