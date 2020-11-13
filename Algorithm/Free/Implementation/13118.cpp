#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int p[4];
	int x, y, r;

	cin >> p[0] >> p[1] >> p[2] >> p[3];
	cin >> x >> y >> r;

	int man = 0;
	for (int i = 0; i < 4; ++i) {
		if (x == p[i]) {
			man = i + 1;
			break;
		}
	}
	cout << man;

	return 0;
}