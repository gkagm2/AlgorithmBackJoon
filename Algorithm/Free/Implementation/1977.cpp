#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	long arr[10001] = {};

	int m, n;
	cin >> m >> n;

	for (int i = 1; i < n; ++i) {
		int r = i * i;
		arr[r] = 1;
	}

	bool isFirst = false;
	int firstNum;
	int sum = 0;
	for (int i = m; i <= n; ++i) {
		if (1 == arr[i]) {
			if (!isFirst) {
				isFirst = true;
				firstNum = i;
			}
			sum += i;
		}
	}

	if (!isFirst)
		cout << -1;
	else {
		cout << sum << "\n";
		cout << firstNum << "\n";
	}
	return 0;
}