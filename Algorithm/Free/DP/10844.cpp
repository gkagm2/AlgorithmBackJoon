#include <iostream>
#include <cstring>
using namespace std;

int dp[101][10];
long long mod = 1000000000LL;
long long ans = 0;

// Top down
int go(int n, int l) {  // l -> last num
	if (n == 1)
		return n >= 1 && n <= 9 ? 1 : 0;

	if (dp[n][l] != -1)
		return dp[n][l];

	if(l == 0)
		return dp[n][l] = go(n - 1, l + 1) % mod;
	if (l == 9)
		return dp[n][l] = go(n - 1, l - 1) % mod;
	return dp[n][l] = (go(n - 1, l - 1) + go(n - 1, l + 1)) % mod;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= 9; ++i) {
		ans = (ans + go(n, i)) % mod;
	}

	ans %= mod;
	cout << ans;

	return 0;
}


// Button up
/*
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			dp[i][j] = 0;
			if (j - 1 >= 0)
				dp[i][j] += dp[i - 1][j - 1];
			if (j + 1 <= 9)
				dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}

	for (int i = 0; i <= 9; ++i)
		ans += dp[n][i];

	ans %= mod;
	cout << ans;

	return 0;
}
*/