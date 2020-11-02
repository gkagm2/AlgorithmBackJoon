#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Vector2 {
	float x;
	float y;
};

float GetDistance(Vector2 v1, Vector2 v2) {
	return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;

	while (t--) {
		Vector2 pos1;
		Vector2 pos2;
		int r1;
		int r2;
		cin >> pos1.x >> pos1.y >> r1;
		cin >> pos2.x >> pos2.y >> r2;

		float distance = GetDistance(pos1, pos2);

		if (r1 < r2)
			swap(r1, r2);

		if (r1 > distance) {
			if (r1 == r2 && pos1.x == pos2.x && pos1.y == pos2.y)
				cout << "-1\n";
			else if (distance < r1 - r2)
				cout << "0\n";
			else if (distance == r1 - r2)
				cout << "1\n";
			else if (distance > r1 - r2)
				cout << "2\n";
		}
		else {
			if (distance == r1 + r2)
				cout << "1\n";
			else if (distance > r1 + r2)
				cout << "0\n";
			else if (distance < r1 + r2)
				cout << "2\n";
		}
	}

	return 0;
}