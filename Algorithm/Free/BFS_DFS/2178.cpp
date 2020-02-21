// BFS (DFS로 하면 queue -> stack으로 변환. 대신 최단거리 안나올 수 있음)
#include <iostream>
#include <queue>
using namespace std;

char map[101][101] = { 0, };
int check[101][101] = { 0, };
int xMapSize, yMapSize;

struct Position {
	int x; 
	int y;
	Position(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

Position MoveDirection(Position pos, int direction) {
	switch (direction) {
	case 0:
		++pos.y;
		break;
	case 1:
		--pos.y;
		break;
	case 2:
		++pos.x;
		break;
	case 3:
		--pos.x;
		break;
	}
	return pos;
}

void BFS(Position pos) {
	queue<Position> q;
	q.push(pos);
	check[pos.y][pos.x] = 1;

	while (!q.empty()) {
		pos = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			Position nPos = MoveDirection(pos, i);

			if (0 > nPos.x || 0 > nPos.y || nPos.x >= xMapSize || nPos.y >= yMapSize) {
				continue;
			}

			// 방문을 하지 않았고 길이면
			if (check[nPos.y][nPos.x] == 0 && map[nPos.y][nPos.x] == '1') { // 1 : 길
				q.push(nPos);
				check[nPos.y][nPos.x] = check[pos.y][pos.x] + 1;
			}
			// 방문을 하지 않았으면
			else if (check[nPos.y][nPos.x] == 0) {
				check[nPos.y][nPos.x] = -1; // 벽이므로  -1로 
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> yMapSize >> xMapSize;
	for (int i = 0; i < yMapSize; i++) {
		for (int j = 0; j < xMapSize; j++) {
			cin >> map[i][j];
		}
	}//맵 입력받음
	BFS(Position(0,0));

	cout << check[yMapSize - 1][xMapSize - 1]; // 좌 하단 목적지
}