#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct Vector2 {
	double x;
	double y;
};

double minDis = 1.797679e+308;
double maxDis = 0;

double GetDistance(const Vector2 v1, const Vector2 v2) {
	return sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Vector2 v[3];
	for (int i = 0; i < 3; ++i) {
		cin >> v[i].x >> v[i].y;
	}

	if ((v[1].x- v[0].x) * (v[2].y - v[0].y) == (v[1].y - v[0].y) * (v[2].x - v[0].x)) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < 3; ++i) {
		double dis1 = GetDistance(v[i], v[(i + 1) % 3]);
		double dis2 = GetDistance(v[i], v[(i + 2) % 3]);

		minDis = min((dis1 + dis2) * 2, minDis);
		maxDis = max((dis1 + dis2) * 2, maxDis);
	}
	
	cout.precision(16);
	cout << maxDis - minDis;

	return 0;
}