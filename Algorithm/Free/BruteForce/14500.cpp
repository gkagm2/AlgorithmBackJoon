#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int map[501][501];
int visit[501][501];
int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };


int dfs(int x, int y, int cnt) {
	if (cnt > 4)
		return 0;

	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		int nX = x + dirX[i];
		int nY = y + dirY[i];

		if (0 <= nX && nX < n && 0 <= nY && nY < m) {
			if (visit[nX][nY] == false) {
				visit[nX][nY] = true;
				ans = max(ans, dfs(nX, nY, cnt + 1) + map[x][y]);
				visit[nX][nY] = false;
			}
		}
	}
	return ans;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visit[i][j] = true;
			ans = max(ans, dfs(i, j, 1));
			visit[i][j] = false;
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 2; ++j) {
			ans = max(ans, map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2]); // で Shape
			ans = max(ans, map[i + 1][j + 1] + map[i][j] + map[i][j + 1] + map[i][j + 2]); //  ぬ Shape
		}
	}

	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			ans = max(ans, map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i + 1][j]); // っ Shape
			ans = max(ans, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1]); // た Shape
		}
	}

	cout << ans;

	return 0;
}