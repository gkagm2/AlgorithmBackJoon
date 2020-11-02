#include <iostream>
#include <cstring>
using namespace std;

int map[8][8];
int originalMap[8][8];
int tempMap[8][8];
int n, m;

// 0 : space,  1 : wall, 2 : virus
enum State {
	eSpace = 0,
	eWall,
	eVirus
};

int dirX[] = { 0, 1, 0, -1 };
int dirY[] = { -1, 0, 1, 0 };
int g_saveAreaCnt = 0;

void Dfs(int _x, int _y) {
	for (int i = 0; i < 4; ++i) {
		int x = _x + dirX[i];
		int y = _y + dirY[i];

		if (x < 0 || y < 0 || x >= n || y >= m)
			continue;
		if (tempMap[y][x] == eWall)
			continue;

		if (tempMap[y][x] == eSpace) {
			tempMap[y][x] = eVirus;
			Dfs(x, y);
		}
	}
}

inline int GetSaveArea(int _map[][8]) {
	int saveAreaCnt = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (_map[i][j] == eSpace)
				++saveAreaCnt;
		}
	}
	return saveAreaCnt;
}

void MakeWall(int _wallCnt) {
	if (_wallCnt >= 3) {
		memcpy(tempMap, map, sizeof(map));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (tempMap[i][j] == eVirus)
					Dfs(j, i);
			}
		}
		int spaceCnt = GetSaveArea(tempMap);
		g_saveAreaCnt = g_saveAreaCnt < spaceCnt ? spaceCnt : g_saveAreaCnt;
		return;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == eSpace) {
				map[i][j] = eWall;
				MakeWall(_wallCnt + 1);
				map[i][j] = eSpace;
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			originalMap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == eSpace) {
				memcpy(map, originalMap, sizeof(originalMap));
				map[i][j] = eWall;
				MakeWall(1);
				map[i][j] = eSpace;
			}
		}
	}

	cout << g_saveAreaCnt;

	return 0;
}