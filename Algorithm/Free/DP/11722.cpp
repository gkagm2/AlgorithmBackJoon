#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[i] < arr[j] && dp[i] < dp[j] + 1)
				dp[i] = 1 + dp[j];
		}
	}

	int maxNum = 0;
	for (int i = 0; i < n; ++i) {
		maxNum = max(dp[i], maxNum);
	}

	cout << maxNum;

	return 0;
}