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
		cout << "1: 노드 추가" << endl;
		cout << "2: 노드 삭제" << endl;
		cout << "3: 연결 리스트의 길이" << endl;
		cout << "0: 종료" << endl;
		cout << "메뉴선택: ";
		cin >> menu;
		
		switch(menu) {
		case 0:
			cout << "종료합니다." << endl;
			shutdown = true;
			break;
		case 1:
			cout << "추가할 자연수 입력: ";
			cin >> inputData;
			append(inputData);
			break;
		case 2:
			cout << "삭제할 자연수 입력: ";
			cin >> inputData;
			remove(inputData);
			break;
		case 3:
			cout << "링크드 리스트의 길이: " << len() << endl;
			break;
		}

		if (shutdown) break;

		printAll();
		cout << endl;
	}

	// 프로그램 종료 시 연결 리스트 할당 해제
	deleteAll();
	cout << len();

	return 0;
}

void append(int pData) {
	if (tail != nullptr) {	// 연결 리스트가 비어있는 경우
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

	if (len() == 0) {	// 연결 리스트가 비어 있는 경우
		cout << "ERROR: 연결 리스트가 비어 있습니다." << endl;
		return;
	}

	while (pointer != nullptr) {	// 연결 리스트가 비어 있지 않은 경우
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

	if (!isDataExist) {				// 사용자가 입력한 DATA가 연결 리스트에 존재하지 않는 경우
		cout << "ERROR: 입력하신 data가 연결 리스트에 없습니다." << endl;
	}
}

int len() {
	int rt = 0;
	if (head == nullptr) return 0;	// 연결 리스트가 비어 있는 경우
	if (head == tail) return 1;		// 연결 리스트 원소가 1개뿐인 경우
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