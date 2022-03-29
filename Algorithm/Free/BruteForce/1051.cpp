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

			for (int pY = curY; pY < y; ++pY) {
				for (int pX = curX; pX < x; ++pX) {
					if (curY == pY && curX == pX)
						continue;

					char rt = map[pY][curX];
					char lb = map[curY][pX];
					char rb = map[pY][pX];

					if (lt == rt && lb == rb && lt == lb) {
						if (pY - curY == pX - curX) {
							int size = (pY + 1 - curY) * (pX + 1 - curX);
							if (size > maxSize)
								maxSize = size;
						}
					}
				}
			}
		}
	}

	cout << maxSize;

	return 0;
}