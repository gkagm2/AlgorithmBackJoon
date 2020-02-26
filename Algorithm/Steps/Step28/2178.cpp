// BFS (DFS�� �ϸ� queue -> stack���� ��ȯ. ��� �ִܰŸ� �ȳ��� �� ����)
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

			// �湮�� ���� �ʾҰ� ���̸�
			if (check[nPos.y][nPos.x] == 0 && map[nPos.y][nPos.x] == '1') { // 1 : ��
				q.push(nPos);
				check[nPos.y][nPos.x] = check[pos.y][pos.x] + 1;
			}
			// �湮�� ���� �ʾ�����
			else if (check[nPos.y][nPos.x] == 0) {
				check[nPos.y][nPos.x] = -1; // ���̹Ƿ�  -1�� 
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
	}//�� �Է¹���
	BFS(Position(0,0));

	cout << check[yMapSize - 1][xMapSize - 1]; // �� �ϴ� ������
}