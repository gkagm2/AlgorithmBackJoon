// use stack reference (1988KB, 0ms)
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<char> stk;

	string str;
	bool isCorrect;

	while (true) {
		isCorrect = true;
		while (!stk.empty()) {
			stk.pop();
		}

		getline(cin, str);

		if (str.compare(".") == 0) {
			break;
		}

		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '.') {
				break;
			}
			if (str[i] == '(' || str[i] == '[') {
				stk.push(str[i]);
			}
			else if ((str[i] == ')' || str[i] == ']')) {
				if (stk.empty()) {
					isCorrect = false;
					break;
				}
				else if (stk.top() == '(' && str[i] == ')' ||
					stk.top() == '[' && str[i] == ']') {
					stk.pop();
				}
				else {
					isCorrect = false;
					break;
				}
			}
		}
		if (!stk.empty()) {
			isCorrect = false;
		}

		if (isCorrect) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}

	return 0;
}

// 1984KB, 4ms
/*
#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	char data;
	Node* next;
	Node() : next(NULL) {}
};

class Stack {
private:
	Node* head;
	int size;

public:
	Stack() : size(0), head(NULL) {
	}
	~Stack() {
		Reset();
	}

	bool IsEmpty() {
		if (size == 0) {
			return true;
		}
		return false;
	}

	int Size() {
		return size;
	}

	char Pop() {
		if (IsEmpty()) {
			return '0';
		}
		Node* node;
		node = head;
		head = head->next;
		--size;

		char data = node->data;
		delete node;
		return data;
	}

	void Push(char data) {
		Node *node = new Node();
		node->data = data;
		if (!IsEmpty()) {
			node->next = head;
		}
		head = node;
		++size;
	}

	char Top() {
		if (size == 0) {
			return 0;
		}
		return head->data;
	}

	void Reset() {
		if (size == 0) {
			return;
		}
		while (head) {
			Node* node = head;
			head = head->next;
			delete node;
		}
		head = NULL;
		size = 0;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Stack stk;

	char str[101];
	bool isCorrect;

	while (true) {
		isCorrect = true;
		stk.Reset();

		cin.getline(str, 101);

		if (strcmp(str, ".") == 0) {
			break;
		}

		for (int i = 0; i < strlen(str); ++i) {
			if (str[i] == '.') {
				break;
			}
			if (str[i] == '(' || str[i] == '[') {
				stk.Push(str[i]);
			}
			else if (str[i] == ')' || str[i] == ']') {
				if (stk.Top() == '(' && str[i] == ')' ||
					stk.Top() == '[' && str[i] == ']') {
					stk.Pop();
				}
				else {
					isCorrect = false;
					break;
				}
			}
		}
		if (!stk.IsEmpty()) {
			isCorrect = false;
		}

		if (isCorrect) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}

	return 0;
}
*/