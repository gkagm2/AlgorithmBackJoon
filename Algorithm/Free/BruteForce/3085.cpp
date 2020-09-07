#include <iostream>
using namespace std;

inline int check(char **&a, const int &n, const int _i, const int _j) {
	int ans = 1;

	int count = 1;
	for (int j = 1; j < n; ++j) {
		if (a[_i][j] == a[_i][j - 1]) {
			++count;
			if (ans < count)
				ans = count;
		}
		else count = 1;
	}
	count = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i][_j] == a[i - 1][_j]) {
			++count;
			if (ans < count)
				ans = count;
		}
		else count = 1;
	}

	return  ans;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	int  ans = 0;
	cin >> n;

	char **a = new char*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new char[n];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// rigth
			if (j + 1 < n) {
				swap(a[i][j], a[i][j + 1]);
				int temp = check(a, n, i, j);
				if (temp > ans)
					ans = temp;
				temp = check(a, n, i, j + 1);
				if (temp > ans)
					ans = temp;
				swap(a[i][j], a[i][j + 1]);
			}
			// bottom
			if (i + 1 < n) {
				swap(a[i][j], a[i + 1][j]);
				int temp = check(a, n, i, j);
				if (temp > ans)
					ans = temp;
				temp = check(a, n, i + 1, j);
				if (temp > ans)
					ans = temp;
				swap(a[i][j], a[i + 1][j]);
			}
		}
	}

	cout << ans;

	delete[] a;
	return 0;
}