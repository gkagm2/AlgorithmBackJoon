#include <iostream>
#include <algorithm>
using namespace std;
#define R 0
#define G 1
#define B 2

int d[1001][3];
int a[1001][3];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int rgb = 0; rgb < 3; ++rgb) {//0 : r, 1 : g , 2 : b
			cin >> a[i][rgb];
		}
	}

	d[1][R] = a[1][R];
	d[1][G] = a[1][G];
	d[1][B] = a[1][B];


	for (int i = 2; i <= n; ++i) {
		d[i][R] = min(d[i - 1][G], d[i - 1][B]) + a[i][R];
		d[i][G] = min(d[i - 1][R], d[i - 1][B]) + a[i][G];
		d[i][B] = min(d[i - 1][R], d[i - 1][G]) + a[i][B];
	}

	cout << min(min(d[n][R], d[n][G]), d[n][B]);

	return 0;
}