// Used DP
#include <iostream>
using namespace std;

int dp[11];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	dp[0] = 1;
	for (int i = 1; i < 11; ++i) {
		dp[i] = dp[i - 1] * i;
	}


	int n, k;
	cin >> n >> k;

	cout << dp[n] / (dp[n - k] * dp[k]);

	return 0;
}

/*
#include <iostream>
using namespace std;

int GetFactorial(int n) {
	int num = 1;
	for (int i = 2; i <= n; ++i) {
		num *= i;
	}
	return num;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	cout << GetFactorial(n) / (GetFactorial(n - k) * GetFactorial(k));

	return 0;
}
*/