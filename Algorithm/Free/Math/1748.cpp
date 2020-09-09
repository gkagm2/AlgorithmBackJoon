#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	int ans = 0;
	int len;

	for (int start = 1, len = 1; start <= n; start *= 10, ++len) {
		int end = start * 10 - 1;
		if (end > n)
			end = n;

		ans += (end - start + 1) * len;
	}
	
	cout << ans;

	return 0;
}


/*
// 1984kb, 588ms
#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int nn;

	cin >> nn;

	int cnt = 0;
	for (int i = 1; i <= nn; ++i) {
		int n = 0;
		n = i;
		while (true) {
			if (n == 0)
				break;
			n = n / 10;
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}
*/