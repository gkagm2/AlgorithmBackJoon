#include <iostream>
using namespace std;

bool map[101][101];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int x1, y1, x2, y2;

	for (int i = 0; i < 4; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; ++y) {
			for (int x = x1; x < x2; ++x) {
				if(!map[y][x])
					map[y][x] = true;
			}
		}
	}

	int area = 0;
	for (int x = 1; x <= 100; ++x) {
		for (int y = 1; y <= 100; ++y) {
			if (map[y][x])
				++area;
		}
	}

	cout << area;

	return 0;
}