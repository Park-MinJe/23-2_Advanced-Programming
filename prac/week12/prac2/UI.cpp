#include "UI.h"

int UI::optionMenu() {
	int op;
	cout << "삽입: 1, 삽입:2, 모두보기:3, 종료:4 >> ";
	cin >> op;

	return op;
}

int UI::shpaeMenu() {
	int op;
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> op;

	return op;
}

int UI::getDeleteIdx() {
	int idx;
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> idx;
	return idx;
}