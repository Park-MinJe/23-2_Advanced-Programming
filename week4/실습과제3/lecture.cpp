#include "lecture.h"

Lecture::Lecture(string pName, int pId, string pAttendance)
    : name(pName), id(pId), attendance(pAttendance)
{
    cout << this->name << " 출석 체크를 시작합니다.\n";
}
Lecture::~Lecture() {
    cout << this->name << " 출석 체크가 완료되었습니다.\n";
}

void Lecture::printStudentAttendance() {
    cout << "이름 : " << this->name << "\n";
    cout << "학번 : " << this->id << "\n";
    cout << "출결(출석, 지각, 결석) : " << this->attendance << "\n";
}