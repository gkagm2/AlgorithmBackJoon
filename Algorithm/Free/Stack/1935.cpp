#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

stack<double> stk;

inline void GetValue(double&a, double&b) {
	a = stk.top(); stk.pop();
	b = stk.top(); stk.pop();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int cnt;
	cin >> cnt;
	cin.ignore();
	char str[510];
	cin >>str;
	int strCnt = strlen(str);
	double num[28] = { 0, };

	// input
	for (int i = 0; i < cnt; ++i) {
		cin >> num[i];
	}
	double a, b;
	// calculate
	for (int i = 0; i < strCnt; ++i) {
		switch (str[i]) {
		case '+': {
			GetValue(b, a);
			stk.push(a + b);
		}
			break;
		case '-': {
			GetValue(b, a);
			stk.push(a - b);
		}
			break;
		case '/': {
			GetValue(b, a);
			stk.push(a / b);
		}
			break;
		case '*': {
			GetValue(b, a);	
			stk.push(a * b);
		}
			break;
		default:
			stk.push(num[str[i] -'A']);
			break;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << stk.top();
	return 0;
}
