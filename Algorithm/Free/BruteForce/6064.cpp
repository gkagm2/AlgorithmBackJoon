#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;

	while (t--) {
		int n, m, x, y;

		cin >> m >> n >> x >> y;

		--x;
		--y;

		int curY = 0;
		int count = x;
		bool isVaild = true;
		while (true) {
			if (count > n * m) {
				isVaild = false;
				break;
			}
			curY = count % n;
			if (y == curY) {
				break;
			}
			count += m;
		}

		if (isVaild)
			cout << count + 1 << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}