#include "lecture.h"
#define STUDENT_NUM 3

int main()
{
    Lecture* arr[3];

    arr[0] = new Lecture("김철수", 2023654321, "출석");
    arr[1] = new Lecture("이유리", 2023987956, "지각");
    arr[2] = new Lecture("이훈이", 2023456789, "결석");

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