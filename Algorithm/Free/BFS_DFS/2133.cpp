#include <iostream>
using namespace std;

int dX[4] = { 0, 1, 0, -1 };
int dY[4] = { 1, 0, -1 ,0 };
int m, n; // 가로, 세로
int map[50][50]; // 0 : wall, 1 : cabbage, 2 : visit

void InitMap(int _x, int _y) {
	for (int y = 0; y < _y; ++y) {
		for (int x = 0; x < _x; ++x) {
			map[y][x] = 0;
		}
	}
}

void Dfs(int _x, int _y) {
	map[_y][_x] = 2;
	for (int i = 0; i < 4; ++i) {
		int x, y;
		x = _x + dX[i];
		y = _y + dY[i];

		if (x >= m || x < 0 || y >= n || y < 0)
			continue;

		if (map[y][x] == 1)
			Dfs(x, y);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;

	int k;
	cin >> t;

	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; ++i) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		int bugCnt = 0;
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < m; ++x) {
				if (map[y][x] == 1)
				{
					++bugCnt;
					Dfs(x, y);
				}
			}
		}

		cout << bugCnt << "\n";
		InitMap(n,m);
	}

	return 0;
}