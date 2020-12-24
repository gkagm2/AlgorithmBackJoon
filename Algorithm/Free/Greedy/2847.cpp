#include <iostream>
using namespace std;

int level[101];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> level[i];
	}
	int decCnt = 0;
	for (int i = n; i >= 2; --i) {
		if (level[i] <= level[i - 1]) {
			int gap = level[i - 1] - level[i] + 1;
			decCnt += gap;
			level[i - 1] -= gap;
		}
	}

	cout << decCnt;

	return 0;
}