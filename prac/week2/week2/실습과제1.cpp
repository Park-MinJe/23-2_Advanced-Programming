#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string name,
        greetings;
    int studentNum,
        yearDate;

    cout << "이름을 입력하시오: ";
    cin >> name;
    cout << "학번을 입력하시오: ";
    cin >> studentNum;
    cout << "날짜를 입력하시오(yyyymmdd): ";
    cin >> yearDate;
    cout << "인삿말을 25자 이내로 입력하시오: ";
    getchar();
    getline(cin, greetings);

    for (int i = 0; i < 10; i++) {
        cout << "\niter: " << i << "\n";
        cout << name << " / " << studentNum << " / " << yearDate << " / " << greetings << "\n";
    }

    return 0;
}