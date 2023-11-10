#include "time.h"

void Time::setHour(int ph) {
    this->h = ph;
}
void Time::setMin(int pm) {
    this->m = pm;
}
void Time::setSec(int ps) {
    this->s = ps;
}

int Time::getTimeAsSec() {
    return this->h * 60 * 60 + this->m * 60 + this->s;
}

void Time::printTime() {
    cout << setfill('0') << setw(2) << this->h << ":" << setfill('0') << setw(2) << this->m << ":" << setfill('0') << setw(2) << this->s << endl;
}