#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> d(n + 1, -1);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	d[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (d[i] < 0 || d[i] > d[i - j] + v[j]) {
				d[i] = d[i - j] + v[j];
			}
		}
	}

	cout << d[n];

	return 0;
}