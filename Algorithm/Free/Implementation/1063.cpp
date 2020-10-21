// 반례를 못찾겠다.
// 일단 보류.

#include <iostream>
#include <string>
#define MAX_MAP_SIZE 8
using namespace std;

struct Vector2 {
	int x;
	int y;
	Vector2() : x(0), y(0){}
	
	Vector2 operator +(const Vector2 *vec) {
		Vector2 tempVec;
		tempVec.x += vec->x;
		tempVec.y += vec->y;
		return tempVec;
	}
};

bool Move(const string &_move, Vector2 & _position) {
	Vector2 direction;

	for (unsigned i = 0; i < _move.size(); ++i) {
		if (_move[i] == 'R')
			direction.x += 1;
		else if (_move[i] == 'L')
			direction.x -= 1;
		else if (_move[i] == 'T')
			direction.y -= 1;
		else if (_move[i] == 'B')
			direction.y += 1;
	}

	Vector2 position;
	position.x = _position.x + direction.x;
	position.y = _position.y + direction.y;
	if (position.x < 0 || position.y < 0 || position.x >= MAX_MAP_SIZE || position.y >= MAX_MAP_SIZE)
		return false;
	
	_position = position;
	return true;
}

void PositionSetting(string _strPos, Vector2 &_pos) {
	_pos.x = _strPos[0] - 'A';
	_pos.y = MAX_MAP_SIZE - (_strPos[1] - '0');
}

void PrintPosition(Vector2 _pos) {
	char x = _pos.x + 'A';
	char y = MAX_MAP_SIZE - _pos.y + '0';
	cout << x << y;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Vector2 kingPos;
	Vector2 stonePos;
	string strStartPos[2];
	int n;

	cin >> strStartPos[0] >> strStartPos[1] >> n;

	PositionSetting(strStartPos[0], kingPos);
	PositionSetting(strStartPos[1], stonePos);

	for (int i = 0; i < n; ++i) {
		string commend;
		cin >> commend;

		Vector2 tempKingPos = kingPos;
		Vector2 tempStonePos = stonePos;

		bool isPosibleToMove = false;
		if (Move(commend, tempKingPos) && Move(commend, tempStonePos))
			isPosibleToMove = true;

		if (isPosibleToMove) {
			kingPos = tempKingPos;
			stonePos = tempStonePos;
		}
	}

	PrintPosition(kingPos);
	cout << "\n";
	PrintPosition(stonePos);

	return 0;
}