#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<char> stk;
	string str;
	string resultStr;
	cin >> str;
	
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			resultStr += str[i];
			continue;
		}

		switch (str[i]) {
		case '(':
			stk.push(str[i]);
			break;
		case ')':
			while (!stk.empty() && stk.top() != '(') {
				resultStr += stk.top();
				stk.pop();
			}
			stk.pop(); // pop '(' 
			break;
		case '*':
		case '/':
			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
				resultStr += stk.top();
				stk.pop();
			}
			stk.push(str[i]);
			break;
		case '+':
		case '-':
			while (!stk.empty() && stk.top() != '(') {
				resultStr += stk.top();
				stk.pop();
			}
			stk.push(str[i]);
			break;
		}
	}
	while (!stk.empty()) {
		resultStr += stk.top();
		stk.pop();
	}

	cout << resultStr;

	return 0;
}
