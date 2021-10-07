#include <iostream>
using namespace std;

char map[64][64] = {};

struct Vec2 {
	int x;
	int y;
};

bool IsAllSameColor(const Vec2& _vStart, const Vec2& _vEnd, char _col) {
	for (int y = _vStart.y; y <= _vEnd.y; ++y) {
		for (int x = _vStart.x; x <= _vEnd.x; ++x) {
			if (_col != map[y][x])
				return false;
		}
	}
	return true;
}

void QuadTree(const Vec2& _vStart, const Vec2& _vEnd) {
	if (_vStart.x == _vEnd.x && _vStart.y == _vEnd.y) {
		cout << map[_vStart.y][_vStart.x];
		return;
	}

	bool isSame = false;
	char output = '0';
	// 전체 검사
	if (IsAllSameColor(_vStart, _vEnd, '0')) {
		isSame = true;
		output = '0';
	}
	if (false == isSame) {
		if (IsAllSameColor(_vStart, _vEnd, '1')) {
			isSame = true;
			output = '1';
		}
	}

	bool isOnlyOneEle = false;
	if (_vStart.y - _vEnd.y > 0 || _vStart.x - _vEnd.x > 0) {
		isOnlyOneEle = true;
	}

	if (!isOnlyOneEle && !isSame)
		cout << "(";
	if (isSame)
		cout << output;

	if (isSame)
		return;

	// 전체검사를 통과하지 못했으면
	Vec2 start;
	Vec2 end;

	// 1사분면 검사
	start.x = _vStart.x;
	start.y = _vStart.y;
	end.x = (_vEnd.x + _vStart.x) / 2;
	end.y = (_vEnd.y + _vStart.y) / 2 ;
	QuadTree(start, end);

	// 2사분면 검사
	start.x = (_vEnd.x + _vStart.x) / 2 + 1;
	start.y = _vStart.y;
	end.x = _vEnd.x;
	end.y = (_vEnd.y + _vStart.y) / 2;
	QuadTree(start, end);

	// 3사분면 검사
	start.x = _vStart.x;
	start.y = (_vEnd.y + _vStart.y) / 2 + 1;
	end.x = (_vEnd.x + _vStart.x) / 2;
	end.y = _vEnd.y;
	QuadTree(start, end);

	// 4사분면 검사
	start.x = (_vEnd.x + _vStart.x) / 2 + 1;
	start.y = (_vEnd.y + _vStart.y) / 2 + 1;
	end.x = _vEnd.x;
	end.y = _vEnd.y;
	QuadTree(start, end);

	if (!isOnlyOneEle)
		cout << ")";
}


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n; 
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char num;
			cin >> num;
			map[i][j] = num;
		}
	}

	Vec2 start = { 0, 0 };
	Vec2 end = { n - 1, n - 1 };
	QuadTree(start, end);

	return 0;
}