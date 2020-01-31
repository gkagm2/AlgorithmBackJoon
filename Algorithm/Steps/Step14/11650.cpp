#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Position {
	int x;
	int y;
};

bool Compare(Position a, Position b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	vector<Position> vec;

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