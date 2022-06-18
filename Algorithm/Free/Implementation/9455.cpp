#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);


	int testcase;
	int map[100][100] = {};

	cin >> testcase;

	for (int t = 0; t < testcase; ++t) {
		// 입력
		int iX, iY;
		cin >> iY >> iX;
		for (int y = 0; y < iY; ++y) {
			for (int x = 0; x < iX; ++x) {
				cin >> map[y][x];
			}
		}

		int moveCnt = 0;
		int emptySpaceY = -1;

		// 맨 마지막줄부터 검사를 시작한다.
		for (int x = 0; x < iX; ++x) {
			emptySpaceY = -1;
			for (int y = iY - 1; y >= 0; --y) {
				// 박스가 존재하지 않는 부분을 찾는다.
				for (int cY = iY - 1; cY >= 0; --cY) {
					if (map[cY][x] == 0) {
						emptySpaceY = cY;
						break;
					}
				}

				// 박스가 존재하면
				if (map[y][x] == 1) {
					// 몇칸 움직이는지 계산한다.
					if (emptySpaceY >= 0) {
						int cnt = emptySpaceY - y;

						// 움직인만큼 누적
						moveCnt += cnt;

						// 박스를 이동시킴
						map[emptySpaceY][x] = 1;
						map[y][x] = 0;
					}
				}
			}
		}
		cout << moveCnt << "\n";
		memset(map, 0, sizeof(map));
	}

	return 0;
}