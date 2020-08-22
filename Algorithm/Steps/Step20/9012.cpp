#include <iostream>
#include <cstring>

using namespace std;

const char* Valid(char* s, const int &length) {
	int cnt = 0;
	for (int i = 0; i < length; ++i) {
		if (s[i] == '(')
			cnt += 1;
		else
			cnt -= 1;

		if (cnt < 0)
			return "NO";
	}

	if (cnt == 0)
		return "YES";
	else
		return "NO";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCnt;

	char str[51];
	int length;

	cin >> testCnt;
	cin.ignore(1024, '\n');
	while (testCnt--) {
		cin.getline(str, 51);
		length = strlen(str);

		const char *answer = Valid(str, length);
		cout << answer << "\n";
	}

	return 0;
}


// use my stack (linked list)
/*

typedef struct Node {
public:
	char data;
	Node *next;
}NODE, *PNODE;

class Stack {
private:
	PNODE head;

	int size;

public:
	Stack() : size(0) {
		head = new NODE();
	}
	~Stack() {
		NODE *tempNode = head;
		while (tempNode->next) {
			NODE *tNode = tempNode;
			delete tNode;
			tempNode = tempNode->next;
		}
	}

	void Push(char data) {
		NODE *node = new NODE();
		node->data = data;
		if (head == NULL) {
			node->next = NULL;
		}
		else {
			node->next = head;
		}

		head = node;
		++size;
	}
	char Pop() {
		if (size == 0) {
			return '0';
		}
		PNODE node = NULL;
		node = head;
		head = head->next;

		char data = node->data;
		delete node;
		--size;

		return data;
	}

	int Size() {
		return size;
	}

	bool IsEmpty() {
		if (size == 0) {
			return true;
		}
		return false;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCnt;
	Stack stk;

	char str[51];
	int length;
	bool isCorrect;

	cin >> testCnt;
	cin.ignore(1024, '\n');
	while (testCnt--) {
		cin.getline(str, 51);
		length = strlen(str);

		// init
		while (!stk.IsEmpty()) {
			stk.Pop();
		}
		isCorrect = true;

		// check
		for (int i = 0; i < length; ++i) {
			if (str[i] == '(') {
				stk.Push(str[i]);
			}
			else if (str[i] == ')') {
				if (stk.Size() == 0) {
					isCorrect = false;
					break;
				}
				stk.Pop();
			}
		}
		if (stk.Size() != 0)
			isCorrect = false;

		// print
		if (isCorrect) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
*/


// use stack reference
/*
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCnt;
	stack<char> stk;
	
	char str[51];
	int length;
	bool isCorrect;

	cin >> testCnt;
	cin.ignore(1024, '\n');
	while (testCnt--) {
		cin.getline(str, 51);
		length = strlen(str);
		
		// init
		while (!stk.empty()) {
			stk.pop();
		}
		isCorrect = true;

		// check
		for (int i = 0; i < length; ++i) {
			if (str[i] == '(') {
				stk.push(str[i]);
			}
			else if (str[i] == ')') {
				if (stk.size() == 0) {
					isCorrect = false;
					break;
				}
				stk.pop();
			}
		}
		if (stk.size() != 0)
			isCorrect = false;

		// print
		if (isCorrect) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
*/