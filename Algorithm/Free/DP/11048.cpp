#include <iostream>
#include <algorithm>
using namespace std;

int maze[1001][1001];
int dp[1001][1001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> maze[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int _max = maze[i][j];
			if(i-1 >=  1 || j-1 >= 1)
				_max = max(dp[i - 1][j - 1] + maze[i][j], _max);
			if(j-1 >= 1)
				_max = max(dp[i][j - 1] + maze[i][j], _max);
			if(i-1 >= 1)
				_max = max(dp[i - 1][j] + maze[i][j], _max);
			dp[i][j] = _max;
		}
	}

	cout << dp[n][m];

	return 0;
}