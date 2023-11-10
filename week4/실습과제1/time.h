#ifndef __TIME_H__
#define __TIME_H__

#include <iostream>
#include<iomanip>

using namespace std;

class Time {
private:
    int h, m, s;
public:
    void setHour(int ph);
    void setMin(int pm);
    void setSec(int ps);

    int getTimeAsSec();

    void printTime();
};

#endif