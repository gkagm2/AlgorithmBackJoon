#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int d[1001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		d[i] = a[i];
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i] && d[i] < d[j] + a[i]) {
				d[i] = d[j] + a[i];
			}
		}
	}

	cout << *max_element(d, d + n) << "\n";
	
	return 0;
}