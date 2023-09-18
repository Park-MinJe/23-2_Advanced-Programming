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

	cout << "학생 수를 입력하세요: ";
	cin >> numOfStudent;

	studentList = new student[numOfStudent];
	for (int i = 0; i < numOfStudent; ++i) {
		cout << "이름을 입력하세요: ";
		cin >> studentList[i].name;

		cout << "학년을 입력하세요: ";
		cin >> studentList[i].grade;

		cout << "성적을 입력하세요: ";
		cin >> studentList[i].score;

		cout << endl;
	}

	for (int i = 0; i < numOfStudent; ++i) {
		cout << "idx = " << i << endl;
		cout << "이름: " << studentList[i].name << endl;
		cout << "학년: " << studentList[i].grade << endl;
		cout << "성적: " << studentList[i].score << endl;
		cout << endl;
	}

	delete[] studentList;

	return 0;
}