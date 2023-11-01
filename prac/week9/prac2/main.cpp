#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define NUM_SIZE 1000
#define MAX_NUM 100

using namespace std;

void mySort(int*& arr, int mode);

int main() {
	int i = 0, sortMode = 0;
	string fn = "input.txt";
	ofstream fout(fn);
	if (!fout) {
		cout << fn << " file is not accessible\n";
		return 0;
	}

	srand((unsigned int)time(NULL));
	for (i = 0; i < NUM_SIZE; ++i) {
		fout << rand() % MAX_NUM + 1 << " ";
	}

	fout.close();

	ifstream fin;
	fin.open(fn);
	if (!fin) {
		cout << fn << " file is not accessible\n";
		return 0;
	}

	int* numArr = new int[NUM_SIZE];
	i = 0;
	while (!fin.eof()) {
		fin >> numArr[i];
		++i;
	}
	fin.close();
	
	cout << "1. 오름차순 정렬, 2. 내림차순 정렬: ";
	cin >> sortMode;
	mySort(numArr, sortMode);
	for (i = 0; i < NUM_SIZE; ++i) {
		cout << numArr[i] << " ";
	}
	cout << "\n";

	delete[] numArr;
}

void mySort(int*& arr, int mode = 1) {
	if(mode == 1)
		sort(arr, arr + NUM_SIZE);
	else if(mode == 2)
		sort(arr, arr + NUM_SIZE, greater<int>());
}