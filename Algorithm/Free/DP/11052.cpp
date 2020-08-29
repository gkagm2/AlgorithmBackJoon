#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Bottom up
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> d(n + 1);
	
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			d[i] = max(d[i], d[i - j] + v[j]);
		}
	}

	cout << d[n];

	return 0;
}