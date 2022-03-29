#include <iostream>
#include <string>
using namespace std;

char map[51][51] = {};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> y >> x;

	for (int i = 0; i < y; ++i)
		for (int j = 0; j < x; ++j)
			cin >> map[i][j];

	int maxSize = 1;

	for (int curY = 0; curY < y; ++curY) {
		for (int curX = 0; curX < x; ++curX) {

			char lt = map[curY][curX];
			int pY = curY;
			int pX = curX;
			for (; pY < y, pX < x; pX++, pY++) {
				if (curY == pY && curX == pX)
					continue;

				char rt = map[pY][curX];
				char lb = map[curY][pX];
				char rb = map[pY][pX];

				if (lt == rt && lb == rb && lt == lb) {
					int size = (pY + 1 - curY) * (pX + 1 - curX);
					if (size > maxSize)
						maxSize = size;
				}
			}
		}
	}

	cout << maxSize;

	return 0;
}