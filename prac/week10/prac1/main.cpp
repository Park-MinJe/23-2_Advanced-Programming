#include "MyQueue.h"

int main() {
	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "ť�� �뷮: " << mQ.capacity() << ", ť�� ũ��: " << mQ.lenght() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.lenght() != 0) {
		cout << mQ.dequeue() << " ";
	}
	cout << endl << "ť�� ���� ũ��: " << mQ.lenght() << endl;
}
