#include <iostream>
#include <stack>
using namespace std;

stack<int > stk;
int *a;
int *ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	a = new int[cnt];
	ans = new int[cnt];

	for (int i = 0; i < cnt; ++i) {
		ans[i] = -1;
		cin >> a[i];
	}

	for (int i = cnt - 1; i >= 0; --i) {
		while (!stk.empty() && stk.top() <= a[i]) {
			stk.pop();
		}
		if (!stk.empty()) {
			ans[i] = stk.top();
		}
		stk.push(a[i]);
	}

	for (int i = 0; i < cnt; ++i) {
		cout << ans[i] << ' ';
	}
	delete[] a;
	delete[] ans;

	return 0;
}
