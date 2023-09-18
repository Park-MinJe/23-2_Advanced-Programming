#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
} typedef node;

node* head, 
	* tail;

void append(int);
void remove(int);
int len();
void printAll();
void deleteAll();

int main() {
	head = nullptr;
	tail = nullptr;

	int menu,
		inputData;
	bool shutdown = false;

	while (1) {
		cout << "1: ��� �߰�" << endl;
		cout << "2: ��� ����" << endl;
		cout << "3: ���� ����Ʈ�� ����" << endl;
		cout << "0: ����" << endl;
		cout << "�޴�����: ";
		cin >> menu;
		
		switch(menu) {
		case 0:
			cout << "�����մϴ�." << endl;
			shutdown = true;
			break;
		case 1:
			cout << "�߰��� �ڿ��� �Է�: ";
			cin >> inputData;
			append(inputData);
			break;
		case 2:
			cout << "������ �ڿ��� �Է�: ";
			cin >> inputData;
			remove(inputData);
			break;
		case 3:
			cout << "��ũ�� ����Ʈ�� ����: " << len() << endl;
			break;
		}

		if (shutdown) break;

		printAll();
		cout << endl;
	}

	// ���α׷� ���� �� ���� ����Ʈ �Ҵ� ����
	deleteAll();
	cout << len();

	return 0;
}

void append(int pData) {
	if (tail != nullptr) {	// ���� ����Ʈ�� ����ִ� ���
		tail->next = new node;
		tail->next->data = pData;
		tail->next->next = nullptr;
		tail = tail->next;
	}
	else {
		tail = new node;
		tail->data = pData;
		tail->next = nullptr;
		head = tail;
	}
}

void remove(int pData) {
	node* pointer = head,
		* post = nullptr;
	bool isDataExist = false;

	if (len() == 0) {	// ���� ����Ʈ�� ��� �ִ� ���
		cout << "ERROR: ���� ����Ʈ�� ��� �ֽ��ϴ�." << endl;
		return;
	}

	while (pointer != nullptr) {	// ���� ����Ʈ�� ��� ���� ���� ���
		if (pointer->data == pData) {
			isDataExist = true;

			if (post != nullptr) {
				post->next = pointer->next;
			}
			else {
				head = pointer->next;
			}

			if (pointer->next == nullptr) {
				tail = post;
			}

			delete pointer;
			break;
		}
		post = pointer;
		pointer = pointer->next;
	}

	if (!isDataExist) {				// ����ڰ� �Է��� DATA�� ���� ����Ʈ�� �������� �ʴ� ���
		cout << "ERROR: �Է��Ͻ� data�� ���� ����Ʈ�� �����ϴ�." << endl;
	}
}

int len() {
	int rt = 0;
	if (head == nullptr) return 0;	// ���� ����Ʈ�� ��� �ִ� ���
	if (head == tail) return 1;		// ���� ����Ʈ ���Ұ� 1������ ���
	if (head != nullptr) {
		node* pointer = head;
		while (pointer != nullptr) {
			rt++;
			pointer = pointer->next;
		}
	}
	return rt;
}

void printAll() {
	node* pointer = head;
	while (pointer != nullptr) {
		cout << "data: " << pointer->data << endl;
		pointer = pointer->next;
	}
}

void deleteAll() {
	if (len() == 0) return;
	if (len() > 0) {
		while (len() != 0) {
			node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
}