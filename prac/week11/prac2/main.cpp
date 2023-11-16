#include "InkJetPrinter.h"
#include "LaserPrinter.h"

int main() {
	int menu, pages;
	char op;

	InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "Hp", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "잉크젯 : " << inkjet->inkJetToString() << "\n";
	cout << "레이저 : " << laser->laserToString() << "\n";

	do {
		cout << "\n프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> menu >> pages;
		switch (menu) {
		case 1:
			inkjet->printInkJet(pages);
			break;
		case 2:
			laser->printLaser(pages);
			break;
		}
		cout << inkjet->inkJetToString() << "\n";
		cout << laser->laserToString() << "\n";
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> op;
	} while (op == 'y');

	cout << "종료하였습니다.\n";

	delete inkjet;
	delete laser;

	return 0;
}