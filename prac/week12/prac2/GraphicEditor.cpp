#include "GraphicEditor.h"

#include <iostream>

GraphicEditor::GraphicEditor() : pStart(nullptr), pLast(nullptr) {
	cout << "그래픽 에디터입니다.\n";
}

void GraphicEditor::start() {
	bool isStoped = false;

	while (!isStoped) {
		int menuOp = UI::optionMenu();
		int shapeOp;
		switch (menuOp) {
		case 1:
			shapeOp = UI::shpaeMenu();
			switch (shapeOp) {
			case 1:
				insert(new Line());
				break;
			case 2:
				insert(new Circle());
				break;
			case 3:
				insert(new Rectangle());
				break;
			}
			break;
		case 2:
			deleteByIdx(UI::getDeleteIdx());
			break;
		case 3:
			showAll();
			break;
		case 4:
			isStoped = true;
			break;
		}
	}
}

void GraphicEditor::insert(Shape* oInsert) {
	if (pStart == nullptr) {
		pStart = oInsert;
		pLast = oInsert;
	}
	else {
		pLast->setNext(oInsert);
		pLast = oInsert;
	}
}

void GraphicEditor::deleteByIdx(int iIdx) {
	if (pStart == nullptr) {
		cout << "도형이 없습니다.\n";
	}
	else {
		int i = 0;
		Shape* prePtr = pStart;
		Shape* curPtr = pStart;
		for (curPtr = pStart; curPtr != nullptr; curPtr = curPtr->getNext()) {
			if (i == iIdx) {
				prePtr->setNext(curPtr->getNext());
				delete curPtr;
				break;
			}
			i++;
			prePtr = curPtr;
		}
	}
}

void GraphicEditor::showAll() {
	int i = 0;
	for (Shape* tmpPtr = pStart; tmpPtr != nullptr; tmpPtr = tmpPtr->getNext()) {
		cout << i++ << ": " << tmpPtr->toString() << "\n";
	}
}