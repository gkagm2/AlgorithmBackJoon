#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101] = {};

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

vector<int> areas;
int sepAreaCnt = 0;
int m, n, k;

void DFS(int& cnt, int curX, int curY) {
	++cnt;
	map[curY][curX] = 2;

	for (int i = 0; i < 4; ++i) {
		int dX = curX + dirX[i];
		int dY = curY + dirY[i];
		if (dY == 2 && dX == 5)
		{
			int a = 3;
		}

		if (dX >= 0 && dY >= 0 && dX < n && dY < m)
		{
			if (map[dY][dX] == 0)
				DFS(cnt, dX, dY);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; ++y) {
			for (int x = x1; x < x2; ++x) {
				map[y][x] = 1;
			}
		}
	}

	int area = 0;
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			if (map[y][x] == 0) {
				area = 0;
				++sepAreaCnt;
				DFS(area, x, y);
				areas.push_back(area);
			}
			
		}
	}

	cout << sepAreaCnt << "\n";
	sort(begin(areas), end(areas));
	for (auto& i : areas)
	{
		cout << i << " ";
	}

	return 0;
}