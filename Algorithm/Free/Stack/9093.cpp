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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;
	cin.ignore	();
	while (cnt--) {
		string str;
		getline(cin, str);
		str += '\n';

		for (char ch : str) {
			if (ch == ' ' || ch == '\n') {
				while (!stk.isEmpty()) {
					cout << stk.front();
					stk.pop();
				}
				cout << ch;
			}
			else {
				stk.push(ch);
			}
		}
	}

	return 0;
}