#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int testCnt;
	cin >> testCnt;

	while (testCnt--) {
		int n, m;
		cin >> n >> m; // n : west, m : east
		
		if (n > (m / 2))
			n = m - n;

		long long answer = 1;
		for (int j = 0; j < n; ++j)
			answer *= (m - j);
		for (int k = 0; k < n; ++k)
			answer /= (k + 1);
			
		cout << answer << "\n";
	}

	return 0;
}