#include <iostream>
using namespace std;

inline int Change(const int& n) {
	return n == 1 ? 0 : 1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	int sw[101];

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> sw[i];
	}

	int stdCnt;
	cin >> stdCnt;

	int sex;
	int idx;

	while (stdCnt--) {
		cin >> sex >> idx;

		if (sex == 1) {
			for (int i = 1; i <= n; ++i) {
				if (i % idx == 0) {
					sw[i] = Change(sw[i]);
				}
			}
		}
		else {
			int l, r;
			l = r = idx;
		
			while (1) {
				if (l - 1 <= 0 || r + 1 > n) break;
				if (sw[l - 1] != sw[r + 1]) break;
				--l;
				++r;
			}
			for (int i = l; i <= r; ++i) {
				sw[i] = Change(sw[i]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if ((i-1) % 20 == 0 && i-1 != 0)
			cout << "\n";
			
		cout << sw[i];
		if (i != n)
			cout << " ";
	}
	return 0;
}