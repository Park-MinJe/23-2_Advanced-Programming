#include <iostream>

using namespace std;

int main()
{
    int n, * arr, i = 0;

    cout << "������ �󸶳� �Է� �������? ";
    cin >> n;
    while (n < 0) {
        cout << "0 �̻��� ���縦 �Է��ϼ���. ";
        cin >> n;
    }

    arr = new int[n];
    while (true) {
        if (i >= n) break;

        cout << "���� �Է� : ";
        cin >> arr[i];
        ++i;
    }

    i = 0;
    cout << "���� ��� : ";
    while (true) {
        if (i >= n) break;

        cout << arr[i] << ", ";
        ++i;
    }
    cout << "\n";

    delete[] arr;

    return 0;
}
