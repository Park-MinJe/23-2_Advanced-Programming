#include "time.h"

int main()
{
    Time t;
    int h, m, s;

    cout << "시간을 입력해주세요:\n";
    cout << "몇 시? ";
    cin >> h;
    t.setHour(h);

    cout << "몇 분? ";
    cin >> m;
    t.setMin(m);

    cout << "몇 초? ";
    cin >> s;
    t.setSec(s);

    cout << "입력한 시간 = ";
    t.printTime();

    cout << "시간을 초로 변환 = " << t.getTimeAsSec() << "\n";

    return 0;
}