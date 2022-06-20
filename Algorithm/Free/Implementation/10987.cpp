#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	char c[5] = { 'a','e','i','o','u' };
	
	char string[101] = {};
	cin >> string;

	int cnt = 0;
	while (string[cnt] != '\0')
		++cnt;

	int moCnt = 0;
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (string[i] == c[j]) {
				++moCnt;
			}
		}
	}

	cout << moCnt;

	return 0;
}