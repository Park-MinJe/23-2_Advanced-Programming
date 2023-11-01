#include <iostream>
#include <string>
using namespace std;

class Computer {
public:
	string name,
		RAM,
		cpu_type,
		cpu_speed;
	void print();
};

void Computer::print() {
	cout << "이름: " << name << endl;
	cout << "RAM: " << RAM << endl;
	cout << "CPU 종류: " << cpu_type << endl;
	cout << "CPU 속도: " << cpu_speed << endl;
}

int main() {
	Computer c;
	c.name = "동국 노트북";
	c.RAM = "16GB";
	c.cpu_type = "인텔 코어i7-12세대";
	c.cpu_speed = "2.1GHz";
	c.print();
}

/** 출력 결과
이름: 동국 노트북
RAM: 16GB
CPU 종류: 인텔 코어i7-12세대
CPU 속도: 2.1GHz
*/