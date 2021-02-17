#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int	n;
	cin >> n;
	
	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		int from, to;
		cin >> from >> to;
		v.push_back(make_pair(from, to));
	}
	sort(v.begin(), v.end());

	int line = 0;
	int prevFrom, prevTo;
	prevFrom = v[0].first;
	prevTo = v[0].second;
	for (int i = 1; i < n; ++i) {
		int from = v[i].first;
		int to = v[i].second;

		if (prevTo >= from) { // 이어져 있음.
			if (to > prevTo)
				prevTo = to;
		}
		else { // 이어져있지 않음.
			line += prevTo - prevFrom;
			prevFrom = from;
			prevTo = to;
		}
	}
	line += prevTo - prevFrom;
	cout << line;

	return 0;
}