// what the heck!
#include <iostream>
#include <vector>
using namespace std;

int board[3][3];
int playerTurn;
vector<int> record;

inline int CheckPlayerTurn() {
	int p1, p2;
	p1 = p2 = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 1)
				p1++;
			if(board[i][j] == 2)
				p2++;
		}
	}

	if (p1 <= p2)
		return 1;
	return 2;
}

inline bool IsFull() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 0)
				return false;
		}
	}
	return true;
}

inline bool CheckBingo(int player) {
	bool isDone = false;

	for (int i = 0; i < 3; ++i) {
		int colCnt = 0;
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == player)
				colCnt++;
			else
				break;
		}
		if (colCnt == 3) {
			return true;
		}
	}

	for (int i = 0; i < 3; ++i) {
		int rowCnt = 0;
		for (int j = 0; j < 3; ++j) {
			if (board[j][i] == player)
				rowCnt++;
			else
				break;
		}
		if (rowCnt == 3) {
			return true;
		}
	}

	int crossCnt = 0;
	for (int i = 0; i < 3; ++i) {
		if (board[i][i] == player)
			crossCnt++;
		else
			break;
	}
	if (crossCnt == 3) {
		return true;
	}

	crossCnt = 0;
	for (int i = 0; i < 3; ++i) {
		if (board[i][2 - i] == player)
			crossCnt++;
		else
			break;
	}
	if (crossCnt == 3) {
		return true;
	}

	return false;
}

inline int SwitchPlayerTurn(int player) {
	return player == 1 ? 2 : 1;
}

void Simulation(int player) {
	if (IsFull()) {
		if (CheckBingo(1)) { record.push_back(1); }
		if (CheckBingo(2)) { record.push_back(2); }
		return;
	}
	
	// Set Stone
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 0) {
				board[i][j] = player; // put stone
				Simulation(SwitchPlayerTurn(player));
				board[i][j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> board[i][j];
		}
	}
	int playerTurn = CheckPlayerTurn();
	int otherPlayer = SwitchPlayerTurn(playerTurn);
	Simulation(playerTurn);

	bool isPlayerWin = false;
	bool isExistOtherPlayerWin = false;
	for (int i = 0; i < record.size(); ++i) {
		if (record[i] == playerTurn) {
			isPlayerWin = true;
			break;
		}
		else if(record[i] == otherPlayer) {
			isExistOtherPlayerWin = true;
		}
	}
	if (isPlayerWin)
		cout << "W";
	else if (isExistOtherPlayerWin)
		cout << "L";
	else
		cout << "D";

	return 0;
}