#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool IsPrime(int n) {
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	int i = n;
	if (n == 1)
	{
		cout << 2;
		return 0;
	}
	while (true) {
		string s = to_string(i);

		// 펠림드롬 체크
		int strSize = s.size();
		bool isSame = true;
		for (int j = 0; j < strSize / 2; ++j) {
			if (s[strSize - j - 1] != s[j]) {
				isSame = false;
				break;
			}
		}
		if (isSame) {
			// 소수 체크
			if (IsPrime(stoi(s))) {
				cout << s;
				break;
			}
		}
		++i;
	}

	return 0;
}