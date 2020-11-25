#include <iostream>
#include <queue>
using namespace std;

struct SLog {
	int x;
	int y;
	int virus;
	SLog(int _x, int _y, int _virus) : x(_x), y(_y), virus(_virus) {}
};

struct Cmp {
	bool operator() (const SLog& a, const SLog& b) {
		return a.virus > b.virus;
	}
};

int map[201][201];
priority_queue<SLog, vector<SLog>, Cmp> pque;
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void BFS(int second, int mapSize) {
	queue<pair<SLog, int>> que; // virus info, time

	// 초반에 바이러스들을 모두 큐에 넣어준다.
	while (!pque.empty()) {
		que.push(make_pair(pque.top(),1));
		pque.pop();
	}

	while (!que.empty()) {
		SLog log = que.front().first;
		int curTime = que.front().second;
		que.pop();

		if (curTime > second)
			continue;
		
		for (int i = 0; i < 4; ++i) {
			int x = log.x + dirX[i];
			int y = log.y + dirY[i];
			
			if (x <= 0 || y <= 0 || x > mapSize || y > mapSize)
				continue;
			if (map[y][x] == 0) {
				map[y][x] = log.virus;
				que.push(make_pair(SLog(x,y,log.virus), curTime + 1));
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, k;
	int s, findX, findY;
	int x, y;

	// Input
	cin >> n >> k;
	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= n; ++x) {
			cin >> map[y][x];
			if (map[y][x] != 0) {
				pque.push(SLog(x, y, map[y][x]));
			}
		}
	}

	cin >> s >> findY >> findX;

	BFS(s, n);

	cout << map[findY][findX];

	return 0;
}