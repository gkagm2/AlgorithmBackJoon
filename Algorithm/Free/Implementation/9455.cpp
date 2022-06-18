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
		// �Է�
		int iX, iY;
		cin >> iY >> iX;
		for (int y = 0; y < iY; ++y) {
			for (int x = 0; x < iX; ++x) {
				cin >> map[y][x];
			}
		}

		int moveCnt = 0;
		int emptySpaceY = -1;

		// �� �������ٺ��� �˻縦 �����Ѵ�.
		for (int x = 0; x < iX; ++x) {
			emptySpaceY = -1;
			for (int y = iY - 1; y >= 0; --y) {
				// �ڽ��� �������� �ʴ� �κ��� ã�´�.
				for (int cY = iY - 1; cY >= 0; --cY) {
					if (map[cY][x] == 0) {
						emptySpaceY = cY;
						break;
					}
				}

				// �ڽ��� �����ϸ�
				if (map[y][x] == 1) {
					// ��ĭ �����̴��� ����Ѵ�.
					if (emptySpaceY >= 0) {
						int cnt = emptySpaceY - y;

						// �����θ�ŭ ����
						moveCnt += cnt;

						// �ڽ��� �̵���Ŵ
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