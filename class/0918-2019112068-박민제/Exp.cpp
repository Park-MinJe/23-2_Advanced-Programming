#include <iostream>
using namespace std;

class Exp {
public:
	int exp,
		base;
	Exp(int pBase, int pExp);
	Exp(int pBase);
	Exp();
	
	int getValue();	// ������ ������ ����Ͽ� ����
	int getBase();	// ���̽� �� ����
	int getExp();	// ���� �� ����
	bool equals(Exp b);	// �� ��ü�� ��ü b�� ���� ������ �Ǻ��Ͽ� ����
};

Exp::Exp(int pBase, int pExp) {
	exp = pExp;
	base = pBase;
}

Exp::Exp(int pBase) {
	base = pBase;
	exp = 1;
}

Exp::Exp() {
	exp = 1;
	base = 1;
}

int Exp::getValue() {
	int rt = 1;
	if (exp == 0) return 1;
	for (int i = 0; i < exp; i++) {
		rt *= base;
	}
	return rt;
}

int Exp::getBase() {
	return base;
}

int Exp::getExp() {
	return exp;
}

bool Exp::equals(Exp b) {
	if (getValue() == b.getValue()) return true;
	return false;
}

int main() {
	Exp a(3, 2);
	Exp b(9);
	Exp c;

	cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << endl;
	cout << "a�� ���̽� " << a.getBase() << ',' << "���� " << a.getExp() << endl;

	if (a.equals(b))
		cout << "���ƿ�~^^" << endl;
	else
		cout << "���� �ʾƿ�!��.��" << endl;
}

/** ��� ���
9 9 1
a�� ���̽� 3,���� 2
���ƿ�~^^
*/