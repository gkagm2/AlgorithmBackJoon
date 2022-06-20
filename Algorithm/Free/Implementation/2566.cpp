#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int map[9][9] = {};

	int maxValue = 0;
	int maxX = 1;
	int maxY = 1;

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int input;
			cin >> input;
			map[i][j] = input;
			if (input > maxValue) {
				maxValue = input;
				maxX = j;
				maxY = i;
			}
		}
	}

	cout << maxValue << "\n" <<  1 + maxY << " " << 1 +maxX;

	return 0;
}