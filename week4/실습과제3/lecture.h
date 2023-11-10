#ifndef __LECTURE_H__
#define __LECTURE_H__

#include <iostream>
#include <string>

using namespace std;

class Lecture {
private:
    string name;
    int id;
    string attendance;
public:
    Lecture(string pName, int pId, string pAttendance);
    ~Lecture();

    void printStudentAttendance();
};

#endif