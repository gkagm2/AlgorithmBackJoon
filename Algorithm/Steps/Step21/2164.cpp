#include <iostream>
#include <queue>
using namespace std;

int main() {

	queue<int> que;
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		que.push(i);
	}
	while (que.size() != 0) {
		if (que.size() == 1) {
			cout << que.front();
			que.pop();
			break;
		}
		que.pop();
		que.push(que.front());
		que.pop();
	}

	return 0;
}

/*
class Queue {
private:
	int *arr;
	int size;
	int headPos;
	int tailPos;
public:
	Queue() : headPos(0), tailPos(0), size(0) {
		arr = new int[500050];
	}
	~Queue() {
		delete[] arr;
	}

	void Push(int data) {
		if (size == 500049) {
			return;
		}

		arr[headPos++] = data;
		++size;
	}

	int Pop() {
		if (tailPos == headPos) {
			return -1;
		}
		--size;
		return arr[tailPos++];
	}
	int Size() {
		return size;
	}
};
*/