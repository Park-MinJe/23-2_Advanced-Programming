#include "lecture.h"
#define STUDENT_NUM 3

int main()
{
    Lecture* arr[3];

    arr[0] = new Lecture("��ö��", 2023654321, "�⼮");
    arr[1] = new Lecture("������", 2023987956, "����");
    arr[2] = new Lecture("������", 2023456789, "�Ἦ");

    cout << "--------------------\n";
    for (int i = 0; i < STUDENT_NUM; ++i) {
        arr[i]->printStudentAttendance();
        cout << "\n";
    }
    cout << "--------------------\n";

    for (int i = 0; i < STUDENT_NUM; ++i) {
        delete arr[i];
    }

    return 0;
}