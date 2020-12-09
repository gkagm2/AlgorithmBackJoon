#include <iostream>
#include <algorithm>
using namespace std;

int dp[10003];
int arr[10003];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 3; i < n + 3; ++i) {
		cin >> arr[i];
	}
	
	for (int i = 3; i < n + 3; ++i) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << *max_element(dp, dp+n + 3);

	return 0;
}	