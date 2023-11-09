#include <iostream>

using namespace std;

int main()
{
    int n, * arr, i = 0;

    cout << "정수를 얼마나 입력 받을까요? ";
    cin >> n;
    while (n < 0) {
        cout << "0 이상의 정루를 입력하세요. ";
        cin >> n;
    }

    arr = new int[n];
    while (true) {
        if (i >= n) break;

        cout << "정수 입력 : ";
        cin >> arr[i];
        ++i;
    }

    i = 0;
    cout << "정수 출력 : ";
    while (true) {
        if (i >= n) break;

        cout << arr[i] << ", ";
        ++i;
    }
    cout << "\n";

    delete[] arr;

    return 0;
}
