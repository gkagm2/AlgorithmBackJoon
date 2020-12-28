#include <iostream>
using namespace std;

int a[1001];
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 44; ++i) {
		a[i - 1] = i*(i + 1) / 2;
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		bool can = false;

		for (int k = 0; k <= 44; ++k) {
			if (a[k] > n)
				break;
			for (int l = 0; l <= 44; ++l) {
				if (a[l] > n)
					break;
				for (int m = 0; m <= 44; ++m) {
					if (a[m] > n) {
						break;
					}

					if (a[k] + a[l] + a[m] == n) {
						can = true;
						goto ESCAPE;
					}
				}
			}
		}
	ESCAPE:
		cout << (can == true ? 1 : 0) << "\n";
	}

	return 0;
}