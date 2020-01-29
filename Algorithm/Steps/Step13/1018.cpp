#include <iostream>
using namespace std;

char plane[50][50];
int width, height;

inline int Check(int hIndex, int wIndex, char a, char b) {
	int cnt = 0;
	for (int h = hIndex; h < hIndex + 8; ++h) {
		for (int w = wIndex; w < wIndex + 8; w += 2) {
			if (h % 2 == 0) {
				if (plane[h][w] != a) {
					++cnt;
				}
				if (plane[h][w + 1] != b) {
					++cnt;
				}
			}
			else {
				if (plane[h][w] != b) {
					++cnt;
				}
				if (plane[h][w + 1] != a) {
					++cnt;
				}
			}
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> height >> width;
	
	for (int h = 0; h < height; ++h) {
		for (int w = 0; w < width; ++w) {
			cin >> plane[h][w];
		}
	}
	int cnt, loopCnt;
	cnt = loopCnt = height * width;
	for (int h = 0; h <= height - 8; ++h) {
		for (int w = 0; w <= width - 8; ++w) {
			cnt = Check(h, w, 'W', 'B');
			if (cnt < loopCnt) {
				loopCnt = cnt;
			}
			cnt = Check(h, w, 'B', 'W');
			if (cnt < loopCnt) {
				loopCnt = cnt;
			}
		}
	}

	cout << loopCnt;

	return 0;
}