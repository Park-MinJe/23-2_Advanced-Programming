#include "InkJetPrinter.h"
#include "LaserPrinter.h"

int main() {
	int menu, pages;
	char op;

	InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "Hp", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "��ũ�� : " << inkjet->inkJetToString() << "\n";
	cout << "������ : " << laser->laserToString() << "\n";

	do {
		cout << "\n������(1:��ũ��, 2:������)�� �ż� �Է�>>";
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
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> op;
	} while (op == 'y');

	cout << "�����Ͽ����ϴ�.\n";

	delete inkjet;
	delete laser;

	return 0;
}