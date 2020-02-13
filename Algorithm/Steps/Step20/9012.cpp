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