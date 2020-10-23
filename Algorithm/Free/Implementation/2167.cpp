#include <iostream>
using namespace std;

int arr[301][301];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	
	int i, j, x, y, k;
	cin >> k;

	while (k--) {
		cin >> i >> j >> x >> y;
		int sum = 0;
		for (int x1 = i - 1; x1 < x; ++x1) {
			for (int y1 = j - 1; y1 < y; ++y1) {
				sum += arr[x1][y1];
			}
		}
		cout << sum << "\n";
	}

	return 0;
}