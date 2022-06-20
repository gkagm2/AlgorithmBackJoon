#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	int cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i * j <= n) {
				++cnt;
			}
			
		}
	}

	cout << cnt;

	return 0;
}