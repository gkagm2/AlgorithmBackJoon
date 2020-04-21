#include <iostream>
#include <string>
using namespace std;

class stack {
private:
	char* arr;
	int cnt;
public:
	stack() : cnt(0) {
		arr = new char[1001];
	}
	~stack() {
		delete[] arr;
	}
	void push(char data) {
		arr[cnt++] = data;
	}

	void pop() {
		if (cnt == 0) {
			return;
		}
		--cnt;
	}
	char front() {
		if (cnt == 0) {
			return -1;
		}
		return arr[cnt - 1];
	}

	int count() {
		return cnt;
	}

	int isEmpty() {
		if (cnt == 0)
			return true;
		else
			return false;
	}
};

stack stk;

inline void StackAllPop() {
	while (!stk.isEmpty()) {
		cout << stk.front();
		stk.pop();
	}
	cout << ' ';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;
	cin.ignore();
	while (cnt--) {
		string str;
		getline(cin, str);
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] != ' ') {
				stk.push(str[i]);
			}
			else {
				StackAllPop();
			}
		}
		StackAllPop();
	}

	return 0;
}