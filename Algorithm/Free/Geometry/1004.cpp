#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Vector2 {
	double x;
	double y;
	Vector2() : x(0), y(0) {}
};
struct Planet {
	struct Vector2 pos;
	double r;
};

double GetDistance(const Vector2 &pos1, const Vector2 &pos2) {
	return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	int n;
	Vector2 pos[2]; // 0 : from, 1 : to
	Vector2 toPos;

	while (t--) {
		int inCnt = 0;
		cin >> pos[0].x >> pos[0].y >> pos[1].x >> pos[1].y;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			Planet p;
			cin >> p.pos.x >> p.pos.y >> p.r;

			int posInPlanetCnt = 0;
			if (p.r - GetDistance(pos[0], p.pos) > 0)
				++posInPlanetCnt;
			if (p.r - GetDistance(pos[1], p.pos) > 0)
				++posInPlanetCnt;
			if (posInPlanetCnt == 1)
				++inCnt;
		}	 

		cout << inCnt << "\n";
	}

	return 0;
}