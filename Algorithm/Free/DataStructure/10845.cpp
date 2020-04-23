#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 10000
class queue {
private:
	int* arr;
	int frontIdx;
	int backIdx;
	int size;
public :
	queue() : size(0), frontIdx(0), backIdx(0){
		arr = new int[MAXSIZE];
	}
	~queue() {
		delete[] arr;
	}

	void Push(int data) {
		if (backIdx % MAXSIZE == frontIdx % MAXSIZE && size != 0)
			return;
		++size;
		arr[backIdx % MAXSIZE] = data;
		++backIdx;
	}
	void Pop() {
		if (size == 0)
			return;
		--size;
		++frontIdx;
	}
	int Size() {
		return size;
	}
	int Empty() {
		if (size == 0)
			return 1;
		return 0;
	}
	int Front() {
		if (size == 0)
			return -1;
		return arr[frontIdx % MAXSIZE];
	}
	int Back() {
		if (size == 0)
			return -1;
		return arr[backIdx-1 % MAXSIZE];
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue que;
	int cnt;
	int data;

	cin >> cnt;
	cin.ignore();

	string commend;
	while (cnt--) {
		cin >> commend;
		if (commend == "push") {
			cin >> data;
			que.Push(data);
		}
		else if (commend == "pop") {
			cout << que.Front() << '\n';
			que.Pop();
		}
		else if (commend == "size") {
			cout << que.Size() << '\n';
		}
		else if (commend == "empty") {
			cout << que.Empty() << '\n';
		}
		else if (commend == "front") {
			cout << que.Front() << '\n';
		}
		else if (commend == "back") {
			cout << que.Back() << '\n';
		}
	}

	return 0;
}
