#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int , int>> v;

	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		v.push_back(make_pair(temp, i));
	}

	sort(v.begin(), v.end());

	int mxSize = 0;
	for (int i = 0; i < n; ++i) {
		mxSize = max(mxSize, v[i].second - i);
	}
	cout << mxSize + 1;

	return 0;
}