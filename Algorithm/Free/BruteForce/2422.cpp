// 시간초과
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int possibleCnt = 0;
int take[3];
vector<pair<int, int >> noV;

inline bool NoFound(const int &a, const int &b, const int &c, const int &d) {
	return ((a == b && c == d) || (c == b && a == d)) ? true : false;
}

void DFS(int _n, int _cnt) {
	if (_cnt > 3) {

		for (int i = 0; i < noV.size(); ++i) {
			if (NoFound(take[0], noV[i].first, take[1], noV[i].second)) return;
			if (NoFound(take[1], noV[i].first, take[2], noV[i].second)) return;
			if (NoFound(take[0], noV[i].first, take[2], noV[i].second)) return;
		}
		++possibleCnt;
		return;
	}
	for (int i = _n; i <= n; ++i) {
		take[_cnt - 1] = i;
		DFS(i + 1, _cnt + 1);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		noV.push_back(make_pair(a, b));
	}

	DFS(1, 1);
	cout << possibleCnt;
	return 0;
}