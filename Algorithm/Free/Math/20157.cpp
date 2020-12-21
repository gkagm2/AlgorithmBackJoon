#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	multiset<pair<double, int>> ms;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;

		double angle;
		int surface;
		if (x == 0)
			angle = 0;
		else
			angle = tan((double)y / x);
		if (x > 0 && y > 0) surface = 1;
		else if (x < 0 && y> 0) surface = 2;
		else if (x < 0 && y < 0) surface = 3;
		else if (x > 0 && y < 0) surface = 4;
		else if (x == 0 && y > 0) surface = 5;
		else if (x == 0 && y < 0) surface = 6;
		else if (x > 0 && y == 0) surface = 7;
		else if (x < 0 && y == 0) surface = 8;
			
		ms.insert(make_pair(angle, surface));
	}

	int cnt = 0;
	pair<double, int> tnum = make_pair(0, 0);
	int tcnt = 0;

	for (auto x : ms) {
		if (tnum.first != x.first || tnum.second != x.second) {
			tnum = x;

			if (cnt < tcnt)
				cnt = tcnt;
			tcnt = 0;
		}
		++tcnt;
	}

	if (cnt < tcnt)
		cnt = tcnt;
	cout << cnt;

	return 0;
}