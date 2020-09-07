#include <iostream>
#include <cstdlib>
using namespace std;

int num;
int brokenCnt; // chanal count
bool brokenNums[10];

int Possible(int c) {
	if (c == 0) {
		return brokenNums[0] ? 0 : 1;
	}

	int len = 0;
	while (c) {
		if (brokenNums[c % 10])
			return 0;
		len += 1;
		c /= 10;
	}

	return len;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> num >> brokenCnt;

	for (int i = 0; i < brokenCnt; ++i) {
		int cNum;
		cin >> cNum;
		brokenNums[cNum] = true;
	}

	int ans = abs(num- 100);

	for (int i = 0; i <= 1000000; ++i) {
		int len = Possible(i);
		if (len > 0) {
			int press = abs(i - num);

			if (ans > press + len)
				ans = press + len;
		}
	}

	cout << ans;

	return 0;
}