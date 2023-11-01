#include <iostream>
using namespace std;

class Exp {
public:
	int exp,
		base;
	Exp(int pBase, int pExp);
	Exp(int pBase);
	Exp();
	
	int getValue();	// 지수를 정수로 계산하여 리턴
	int getBase();	// 베이스 값 리턴
	int getExp();	// 지수 값 리턴
	bool equals(Exp b);	// 이 객체와 객체 b의 값이 같은지 판별하여 리턴
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
	cout << "a의 베이스 " << a.getBase() << ',' << "지수 " << a.getExp() << endl;

	if (a.equals(b))
		cout << "같아요~^^" << endl;
	else
		cout << "같지 않아요!ㅠ.ㅠ" << endl;
}

/** 출력 결과
9 9 1
a의 베이스 3,지수 2
같아요~^^
*/