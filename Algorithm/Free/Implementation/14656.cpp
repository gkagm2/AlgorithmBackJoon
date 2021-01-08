#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t != i + 1)
			++cnt;
	}
	cout << cnt;

	return 0;
}