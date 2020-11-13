#include <iostream>
using namespace std;

int dp[100001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		dp[i] = num + dp[i - 1];
	}

	int minN, maxN;
	while (m--) {
		cin >> minN >> maxN;
		cout << dp[maxN] - dp[minN - 1] << "\n";
	}

	return 0;
}