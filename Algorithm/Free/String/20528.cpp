#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	string str;
	string before;

	bool isOk1 = true;
	bool isOk = true;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> str;
		
		for (int j = 0; j < str.size() >> 1; ++j) { // 펠린드롬 체크
			if (str[j] != str[str.size() - 1 -j]) {
				isOk = false;
				break;
			}
		}
		if (!isOk)
			break;

		if (i > 0) {
			if (before[0] != str[0]) {
				isOk1 = false;
				break;
			}
		}

		before = str;
	}
	if (isOk && isOk1)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
	return 0;
}