#include <iostream>
#include <math.h>
using namespace std;

char map[101][101];
bool visit[101][101];

int n, m;

int wCnt = 0;
int bCnt = 0;

int dirX[] = { 0,1,0,-1 };
int dirY[] = { 1,0,-1,0 };

int g_cnt = 0;
void DFS(int _x, int _y, const char &_curTeam) { // start position
	visit[_y][_x] = true;
	++g_cnt;

	for (int i = 0; i < 4; ++i) {
		int x = _x + dirX[i];
		int y = _y + dirY[i];

		if (x <= 0 || y <= 0 || x > n || y > m || map[y][x] != _curTeam)
			continue;
		if (visit[y][x] == true)
			continue;
		DFS(x, y, _curTeam);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (visit[i][j] == false) {
				g_cnt = 0;
				char curTeam = map[i][j];
				DFS(j, i, curTeam);
				if (curTeam == 'W')
					wCnt += pow(g_cnt,2);
				else
					bCnt += pow(g_cnt, 2);
			}
		}
	}

	cout << wCnt << " " << bCnt;

	return 0;
}