#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	short cnt = 0;
	int x;

	cin >> x;

	while(x) {
		cnt += x & 1; // x % 2
		x = x >> 1; // x / 2
	}
	cout << cnt;

	return 0;
}