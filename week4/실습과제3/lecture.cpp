#include "lecture.h"

Lecture::Lecture(string pName, int pId, string pAttendance)
    : name(pName), id(pId), attendance(pAttendance)
{
    cout << this->name << " �⼮ üũ�� �����մϴ�.\n";
}
Lecture::~Lecture() {
    cout << this->name << " �⼮ üũ�� �Ϸ�Ǿ����ϴ�.\n";
}

void Lecture::printStudentAttendance() {
    cout << "�̸� : " << this->name << "\n";
    cout << "�й� : " << this->id << "\n";
    cout << "���(�⼮, ����, �Ἦ) : " << this->attendance << "\n";
}