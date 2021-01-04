#include <iostream>
using namespace std;

enum state { tie, p1Win, p2Win, play };

// 귀찮다 최적화 안함 대충하자
int CheckWinner(int map[][3]) {
	
	int curState = tie;
	
	int p1cnt = 0;
	int p2cnt = 0;

	for (int v = 0; v < 3; ++v) {
		// 가로 
		for (int i = 0; i < 3; ++i) {
			if (map[v][i] == 1)
				++p1cnt;
			else if (map[v][i] == 2)
				++p2cnt;
		}

		if (p1cnt == 3)
			return p1Win;
		else if (p2cnt == 3)
			return p2Win;

		p1cnt = p2cnt = 0;

		// 세로 검사
		for (int i = 0; i < 3; ++i) {
			if (map[i][v] == 1)
				++p1cnt;
			else if (map[i][v] == 2)
				++p2cnt;
		}

		if (p1cnt == 3)
			return p1Win;
		else if (p2cnt == 3)
			return p2Win;

		p1cnt = p2cnt = 0;
	}
	// 좌상 우하 대각선 검사
	for (int i = 0; i < 3; ++i) {
		if (map[i][i] == 1)
			++p1cnt;
		else if (map[i][i] == 2)
			++p2cnt;
	}

	if (p1cnt == 3)
		return p1Win;
	else if (p2cnt == 3)
		return p2Win;
	p1cnt = p2cnt = 0;



	// 우상 좌하 대각선 검사
	for (int i = 0; i < 3; ++i) {
		if (map[i][2-i] == 1)
			++p1cnt;
		else if (map[i][2-i] == 2)
			++p2cnt;
	}

	if (p1cnt == 3)
		return p1Win;
	else if (p2cnt == 3)
		return p2Win;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (map[i][j] == 0)
				return play;
		}
	}

	return tie;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int map[3][3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			map[i][j] = 0;
	

	int player; // 1 or 2
	cin >> player;

	while (true) {
		int state = CheckWinner(map);
		if (state == tie || state == p1Win || state == p2Win) {
			cout << state;
			break;
		}

		int x, y;
		cin >> x >> y;
		map[y-1][x-1] = player;
		player = (player == 1) ? 2 : 1;
	}

	return 0;
}