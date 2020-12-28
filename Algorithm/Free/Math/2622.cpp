#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		for (int j = i; j <= n - i - j; ++j) {
			int longest = n - i - j;
			if (i + j > longest) cnt++;
		}
	}
	cout << cnt;

	return 0;
}