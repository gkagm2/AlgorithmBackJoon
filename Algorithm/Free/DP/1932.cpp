#include <iostream>
#include <algorithm>
using namespace std;

int a[502][502];
int d[502][502];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			cin >> a[i][j];
		}
	}

	d[0][0] = a[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
		}
	}

	int secNodeCnt = (n - 1) *(n) / 2;
	int leapNodeCnt = n * (n + 1) / 2;
	
	int maxNum = 0;
	for (int i = 0; i < leapNodeCnt - secNodeCnt; ++i) {
		maxNum = max(maxNum, d[n][i]);
	}

	cout << maxNum;
	return 0;
}