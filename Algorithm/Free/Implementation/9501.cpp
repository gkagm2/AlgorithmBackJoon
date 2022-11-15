#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		int n, d, v, f, c;
		cin >> n >> d;


		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v >> f >> c;

			int res = v * f / c;
			if (res >= d)
				++cnt;
		}
		cout << cnt << "\n";
	}

	return 0;
}