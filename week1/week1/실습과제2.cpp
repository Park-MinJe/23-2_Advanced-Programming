#include <iostream>

using namespace std;

struct student {
	char name[30];
	int grade;
	int score;
} typedef student;

int main() {
	int numOfStudent = 0, i = 0;
	student* studentList = 0;

	cout << "�л� ���� �Է��ϼ���: ";
	cin >> numOfStudent;

	studentList = new student[numOfStudent];
	for (int i = 0; i < numOfStudent; ++i) {
		cout << "�̸��� �Է��ϼ���: ";
		cin >> studentList[i].name;

		cout << "�г��� �Է��ϼ���: ";
		cin >> studentList[i].grade;

		cout << "������ �Է��ϼ���: ";
		cin >> studentList[i].score;

		cout << endl;
	}

	for (int i = 0; i < numOfStudent; ++i) {
		cout << "idx = " << i << endl;
		cout << "�̸�: " << studentList[i].name << endl;
		cout << "�г�: " << studentList[i].grade << endl;
		cout << "����: " << studentList[i].score << endl;
		cout << endl;
	}

	delete[] studentList;

	return 0;
}