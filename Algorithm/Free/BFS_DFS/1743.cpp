#include <iostream>
#include <algorithm>
using namespace std;

int map[100][100];
bool visit[100][100];
int n, m, k;

int dirY[4] = { 1,0,-1,0 };
int dirX[4] = { 0,1,0,-1 };

int maxCnt = 0;

void DFS(int _x,int _y, int& _cnt) {
	visit[_y][_x] = true;
	_cnt++;
	for (int i = 0; i < 4; ++i) {
		int moveX = _x + dirX[i];
		int moveY = _y + dirY[i];
		
		if (moveX < 0 || moveY < 0 || moveX >= m || moveY >= n || map[moveY][moveX] == 0)
			continue;
		if (!visit[moveY][moveX] && map[moveY][moveX] == 1)
			DFS(moveX, moveY, _cnt);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	
	cin >> n >> m >> k;
	
	int r, c;
	for (int i = 0; i < k; ++i) {
		cin >> r >> c;
		map[r - 1][c - 1] = 1; // 1 : trash
	}
			
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (!visit[y][x] && map[y][x] == 1) {
				int cnt = 0;
				DFS(x, y, cnt);
				maxCnt = max(cnt, maxCnt);
			}
		}
	}
	cout << maxCnt;
	return 0;
}