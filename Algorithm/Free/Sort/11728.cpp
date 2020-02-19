#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int *a = new int[n];
	int *b = new int[m];
	int *c = new int[n + m];

	// merge sort¿Í ¶È°°³ß

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	int kIndex = 0;
	int aStart = 0;
	int bStart = 0;
	while (aStart < n && bStart < m) {
		if (a[aStart] > b[bStart]) {
			c[kIndex++] = b[bStart++];
		}
		else {
			c[kIndex++] = a[aStart++];
		}
	}

	if (aStart >= n) {
		for (int i = bStart; i < m; ++i) {
			c[kIndex++] = b[i];
		}
	}
	else if(bStart >= m) {
		for (int i = aStart; i < n; ++i) {
			c[kIndex++] = a[i];
		}
	}

	for (int i = 0; i < n+m; ++i) {
		cout << c[i] << ' ';
	}
	
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}