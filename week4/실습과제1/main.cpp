#include "time.h"

int main()
{
    Time t;
    int h, m, s;

    cout << "�ð��� �Է����ּ���:\n";
    cout << "�� ��? ";
    cin >> h;
    t.setHour(h);

    cout << "�� ��? ";
    cin >> m;
    t.setMin(m);

    cout << "�� ��? ";
    cin >> s;
    t.setSec(s);

    cout << "�Է��� �ð� = ";
    t.printTime();

    cout << "�ð��� �ʷ� ��ȯ = " << t.getTimeAsSec() << "\n";

    return 0;
}