#include <iostream>
using namespace std;

class Stack {
private:
	int arr[100000];
	int pos;
	
public:
	Stack() : pos(0) {}

	int Pop() {
		if (pos == 0)
			return -1;

		return arr[--pos];
	}
	void Push(int e) {
		arr[pos++] = e;
	}

	bool IsEmpty() {
		if (pos == 0) {
			return true;
		}
		return false;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Stack stk;
	
	int n, inputCnt;
	int sum = 0;
	cin >> inputCnt;

	while (inputCnt--) {
		cin >> n;
		if (n == 0) {
			stk.Pop();
		}
		else {
			stk.Push(n);
		}
	}

	while (!stk.IsEmpty()) {
		sum += stk.Pop();
	}

	cout << sum;

	return 0;
}