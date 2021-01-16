#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos {
	double x;
	double y;
};

bool Cmp(const Pos& a, const Pos& b) {
	if (a.x <= b.x) {
		if (a.y < b.y)
			return true;
		return false;
	}
	return false;
}

inline double Distance(const Pos& a, const Pos& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) *(a.y - b.y);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n;
	vector<Pos> v(4);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		vector<double> dis[4];
		for (int j = 0; j < v.size(); ++j) {
			cin >> v[j].x >> v[j].y;
		}

		int size = v.size();
		for (int j = 0; j < v.size(); ++j) {
			for (int k = 0; k< v.size(); ++k) {
				if (k == j)
					continue;
				dis[j].push_back(Distance(v[j], v[k]));
			}
			sort(dis[j].begin(), dis[j].end());
		}

		bool isOk = true;
		for (int j = 1; j <= 4; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (dis[j % 4][k] != dis[j - 1][k])
					isOk = false;
			}
			if (isOk == false)
				break;
		}

		if (isOk)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}