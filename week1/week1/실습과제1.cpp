#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int intArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char charArr[][30] = { "Hello, world!", "This is C programming.", "I am Bard." };

	int arrSum = 0,
		strLen, 
		longestStr = 0;

	// 배열의 합 구하기
	for (int i = 0; i < sizeof(intArr) / sizeof(int); i++) {
		arrSum += intArr[i];
	}

	cout << "배열의 합: " << arrSum << endl;

	// 배열에서 가장 긴 문자열의 길이 구하기
	for (int i = 0; i < sizeof(charArr) / sizeof(charArr[0]); i++) {
		strLen = strlen(charArr[i]);
		if (longestStr < strLen) {
			longestStr = strLen;
		}
	}
	cout << "배열에서 가장 긴 문자열의 길이: " << longestStr << endl;

	return 0;
}