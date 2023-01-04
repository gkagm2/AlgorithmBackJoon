#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		int minNum = 1000000;
		int maxNum = -1000000;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			minNum = num < minNum ? num : minNum;
			maxNum = num > maxNum ? num : maxNum;
		}

		cout << minNum << " " << maxNum << "\n";
	}

	return 0;
}