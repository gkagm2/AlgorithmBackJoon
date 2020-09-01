#include <iostream>
#include <algorithm>
using namespace std;

int d[1001];
int a[1001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; ++i) {
		d[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] += 1;
			}
		}
	}

	cout << *max_element(d, d + n);

	return 0;
}