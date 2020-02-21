#include <iostream>
#include <queue>

using namespace std;

char border[501][501];
int visited[501][501] = { 0, };
int paintCnt = 0;

struct Position {
	int x;
	int y;

	Position() : x(0), y(0) {}
	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Position operator+(Position pos) {
		pos.x += x;
		pos.y += y;
		return pos;
	}
	bool operator==(const int num) {
		if (x == num && y == num) {
			return true;
		}
		return false;
	}
};

Position MoveDirection(Position pos, int dir) {
	switch (dir) {
	case 0:
		--pos.y; // up
		break;
	case 1:
		++pos.y; // down
		break;
	case 2:
		++pos.x; // right
		break;
	case 3:
		--pos.x; // left
		break;
	}
	return pos;
}

int BFS(Position pos, const Position mapSize) {
	queue<Position> q;
	q.push(pos);
	int area = 0;
	visited[pos.y][pos.x] = 1;

	while (!q.empty()) {
		pos = q.front();
		q.pop();
		++area;

		for (int dir = 0; dir < 4; ++dir) {
			Position nPos = MoveDirection(pos, dir);

			if (nPos.x < 0 || nPos.y < 0 || nPos.x >= mapSize.x || nPos.y >= mapSize.y) {
				continue;
			}
			if (visited[nPos.y][nPos.x] == 0 && border[nPos.y][nPos.x] == '1') {
				q.push(nPos);
				visited[nPos.y][nPos.x] = 1;
			}
			else if (visited[nPos.y][nPos.x] == 0) {
				visited[nPos.y][nPos.x] = -1;
			}
		}
	}
	return area; // ≥–¿Ã∏¶ ∏Æ≈œ
}

void BoardSetting(int xSize, int ySize) {
	for (int y = 0; y < ySize; ++y) {
		for (int x = 0; x < xSize; ++x) {
			cin >> border[y][x];
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Position mapSize;
	cin >> mapSize.y >> mapSize.x;

	BoardSetting(mapSize.x, mapSize.y);
	int maxArea = 0;
	
	for (int y = 0; y < mapSize.y; ++y) {
		for (int x = 0; x < mapSize.x; ++x) {
			if (visited[y][x] == 0 && border[y][x] == '1') {
				Position startPos(x,y);
				int area = BFS(startPos, mapSize);
				++paintCnt;
				maxArea = max(area, maxArea);
			}
		}
	}

	cout << paintCnt << '\n';
	cout << maxArea;
	
	return 0;
}