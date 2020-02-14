#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
	int *arr;
	int size;
	int headPos;
	int tailPos;
	int length;

public:
	Queue() : headPos(0), tailPos(0), size(0){
		arr = new int[2000000];
	}
	~Queue() {
		delete[] arr;
	}
	
	void Push(int data) {
		if (tailPos == 1999999) {
			return;
		}
		++size;
		arr[tailPos++] = data;
	}

	int Pop() {
		if (IsEmpty()) {
			return -1;
		}
		--size;
		return arr[headPos++];
	}

	int IsEmpty() {
		if (headPos == tailPos) {
			return 1;
		}
		return 0;
	}

	int Size() {
		return size;
	}

	int Front() {
		if (IsEmpty()) {
			return -1;
		}
		return arr[headPos];
	}

	int Back() {
		if (IsEmpty()) {
			return -1;
		}
		return arr[tailPos - 1];
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCnt;
	string command;
	Queue que;
	
	cin >> testCnt;
	while (testCnt--) {
		cin >> command;
		if (command.compare("push") == 0) {
			int data;
			cin >> data;
			que.Push(data);
		}
		else if (command.compare("pop") == 0) {
			cout << que.Pop() << '\n';
		}
		else if (command.compare("front") == 0) {
			cout << que.Front() << '\n';
		}
		else if (command.compare("back") == 0) {
			cout << que.Back() << '\n';
		}
		else if (command.compare("size") == 0) {
			cout << que.Size() << '\n';
		}
		else if (command.compare("empty") == 0) {
			cout << que.IsEmpty() << '\n';
		}
	}

	return 0;
}