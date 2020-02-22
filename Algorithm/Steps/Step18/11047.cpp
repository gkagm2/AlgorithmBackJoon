#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int coinType[10];
	int n, k;
	int coinCnt = 0;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> coinType[i];
	}

	for (int i = n - 1; i >= 0; --i) {
		if (k == 0)
			break;

		int coin = coinType[i];
		if (k >= coin) {
			coinCnt += (k / coin);
			k = k % coin;
		}
	}
	cout << coinCnt;

	return 0;
}