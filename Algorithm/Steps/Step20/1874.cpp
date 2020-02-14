#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<int> stk;
	vector<char> vec;
	int testCnt;
	cin >> testCnt;
	int n;
	int i = 1;
	bool isNo = false;

	while (testCnt--) {
		cin >> n;

		for (; i <= n; ++i) {
			stk.push(i);
			vec.push_back('+');
		}
		while (!stk.empty()) {
			if (stk.top() > n) {
				isNo = true;
				break;
			}
			if (stk.top() == n) {
				vec.push_back('-');
				stk.pop();
				break;
			}
			stk.pop();
		}

		if (isNo) {
			break;
		}
	}

	if (isNo) {
		cout << "NO" << '\n';
	}
	else {
		for (int i = 0; i < vec.size(); ++i) {
			cout << vec[i] << '\n';
		}
	}

	return 0;
}