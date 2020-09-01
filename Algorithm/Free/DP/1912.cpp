#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];
int d[100001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	} 

	d[1] = a[1];
	for (int i = 2; i <= n; ++i) {
		d[i] = max(0, d[i - 1]) + a[i];
	}

	cout << *max_element(d + 1, d + n + 1);
	return 0;
}