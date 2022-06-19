#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		int yScore = 0;
		int kScore = 0;
		for (int i = 0; i < 9; ++i) {
			int y, k;
			cin >> y >> k;
			yScore += y;
			kScore += k;
		}

		if (yScore == kScore)
			cout << "Draw\n";
		else if (yScore > kScore)
			cout << "Yonsei\n";
		else
			cout << "Korea\n";
	}

	return 0;
}