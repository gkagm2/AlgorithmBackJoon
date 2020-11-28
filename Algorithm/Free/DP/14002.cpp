#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int dp[1001];
int pre[1001];
int ar[1001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	int len = 0;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
	}

	stack<int> stk;

	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		pre[i] = -1;
		for (int j = 0; j < i; ++j) {
			if (dp[j] + 1 > dp[i] && ar[j] < ar[i]) {
				dp[i] = dp[j] + 1;
				pre[i] = j;
			}
		}
	}

	int idx = 0;
	int maxLen = dp[0];
	for (int i = 1; i < n; ++i) {
		if (dp[i] > maxLen) {
			maxLen = dp[i];	
			idx = i;
		}
	}
	
	cout << maxLen << "\n";

	while (idx >= 0) {
		stk.push(ar[idx]); 
		idx = pre[idx];
	}

	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	return 0;
}