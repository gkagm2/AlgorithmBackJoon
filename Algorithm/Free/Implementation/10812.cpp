#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void Rotate(vector<int>& _vec, int _l, int _r, int _m) {
	vector<int> lvec;
	vector<int> rvec;
	lvec.resize(max(0, _m - _l));
	rvec.resize(max(0,_r - _m + 1));

	int idx = 0;
	for (int i = _l; i <= _m - 1; ++i)
		lvec[idx++] = _vec[i];
	idx = 0;
	for (int i = _m; i <= _r; ++i)
		rvec[idx++] = _vec[i];

	idx = _l;
	for (int i = 0; i < rvec.size(); ++i)
		_vec[idx++] = rvec[i];

	for (int i = 0; i < lvec.size(); ++i)
		_vec[idx++] = lvec[i];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector<int> vec;

	vec.resize(n);
	for (int i = 0; i < n; ++i)
		vec[i] = i + 1;

	for (int i = 0; i < m; ++i) {
		int left, mid, right;
		cin >> left >> right >> mid;
		Rotate(vec, left - 1, right - 1, mid - 1);
	}

	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";

	return 0;
}