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
	cout << "�̸�: " << name << endl;
	cout << "RAM: " << RAM << endl;
	cout << "CPU ����: " << cpu_type << endl;
	cout << "CPU �ӵ�: " << cpu_speed << endl;
}

int main() {
	Computer c;
	c.name = "���� ��Ʈ��";
	c.RAM = "16GB";
	c.cpu_type = "���� �ھ�i7-12����";
	c.cpu_speed = "2.1GHz";
	c.print();
}

/** ��� ���
�̸�: ���� ��Ʈ��
RAM: 16GB
CPU ����: ���� �ھ�i7-12����
CPU �ӵ�: 2.1GHz
*/