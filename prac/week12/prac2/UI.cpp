#include "UI.h"

int UI::optionMenu() {
	int op;
	cout << "����: 1, ����:2, ��κ���:3, ����:4 >> ";
	cin >> op;

	return op;
}

int UI::shpaeMenu() {
	int op;
	cout << "��:1, ��:2, �簢��:3 >> ";
	cin >> op;

	return op;
}

int UI::getDeleteIdx() {
	int idx;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> idx;
	return idx;
}