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

    cout << "�̸��� �Է��Ͻÿ�: ";
    cin >> name;
    cout << "�й��� �Է��Ͻÿ�: ";
    cin >> studentNum;
    cout << "��¥�� �Է��Ͻÿ�(yyyymmdd): ";
    cin >> yearDate;
    cout << "�λ��� 25�� �̳��� �Է��Ͻÿ�: ";
    getchar();
    getline(cin, greetings);

    for (int i = 0; i < 10; i++) {
        cout << "\niter: " << i << "\n";
        cout << name << " / " << studentNum << " / " << yearDate << " / " << greetings << "\n";
    }

    return 0;
}