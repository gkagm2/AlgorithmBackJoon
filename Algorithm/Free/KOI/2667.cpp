/*
그래프 이론
그래프 탐색
너비 우선 탐색
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool visit[25][25];
string arr[25];
int dirX[4] = { 0, 1, -1, 0 };
int dirY[4] = { 1, 0, 0, -1 };
int n;
vector<int> ans;
int cnt = 0;

void Dfs(int _x, int _y) {
	visit[_y][_x] = true;
	++cnt;
	for (int i = 0; i < 4; ++i) {
		int dx = dirX[i] + _x;
		int dy = dirY[i] + _y;
		if (dx < 0 || dy < 0 || dx >= n || dy >= n)
			continue;

		if (visit[dy][dx] == false && arr[dy][dx] == '1') {
			Dfs(dx, dy);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (visit[y][x] == false && arr[y][x] == '1') {
				cnt = 0;
				Dfs(x, y);
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << "\n";
	}

	return 0;
}