#include <iostream>
#include <algorithm>
using namespace std;

int d[301][2];
int a[301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int num;
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		a[i] = num;
	}

	d[0][0] = d[0][1] = 0;
	d[1][0] = d[1][1] = a[1];

	for (int i = 2; i <= n; ++i) {
		d[i][0] = max(d[i - 2][1], d[i-2][0]) + a[i];
		d[i][1] = d[i - 1][0] + a[i];
	}

	cout << max(d[n][0] , d[n][1]);

	return 0;
}