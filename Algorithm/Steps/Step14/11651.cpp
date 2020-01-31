#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Position {
	int x;
	int y;
};

bool Compare(Position a, Position b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	vector<Position> vec;
	cin >> cnt;
	
	for (int i = 0; i < cnt; ++i) {
		Position pos;
		cin >> pos.x >> pos.y;
		vec.push_back(pos);
	}

	sort(vec.begin(), vec.end(), Compare);

	for (int i = 0; i < cnt; ++i) {
		cout << vec[i].x << ' ' << vec[i].y << '\n';
	}
	return 0;
}