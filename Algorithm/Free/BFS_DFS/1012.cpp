// 1992KB
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
		InitMap(n, m);
	}

	return 0;
}

/*
#include <iostream>
#include <stack>
#include <queue>
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

// Bfs로 할 경우 메모리 초과.
void Bfs(int _x, int _y) {
	queue<pair<int, int>> que;
	que.push(make_pair(_x,_y));

	while (!que.empty()) {
		int curX = que.front().first;
		int curY = que.front().second;
		que.pop();
		map[curY][curX] = 2;

		for (int i = 0; i < 4; ++i) {
			int x = curX + dX[i];
			int y = curY + dY[i];

			if (x < 0 || x >= m || y < 0 || y >= n)
				continue;

			if (map[y][x] == 1) {
				que.push(make_pair(x, y));
			}
		}
	}
}

// 2124KB
void Dfs(int _x, int _y) {
	stack<pair<int, int>> stk;

	stk.push(make_pair(_x, _y));

	while (!stk.empty()) {
		int curX = stk.top().first;
		int curY = stk.top().second;
		stk.pop();
		map[curY][curX] = 2;

		for (int i = 0; i < 4; ++i) {
			int x = curX + dX[i];
			int y = curY + dY[i];

			if (x < 0 || x >= m || y < 0 || y >= n)
				continue;

			if (map[y][x] == 1)
				stk.push(make_pair(x, y));
		}
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
				if (map[y][x] == 1) {
					Dfs(x, y);
					++bugCnt;
				}
			}
		}

		cout << bugCnt << "\n";
		InitMap(n, m);
	}

	return 0;
}
*/