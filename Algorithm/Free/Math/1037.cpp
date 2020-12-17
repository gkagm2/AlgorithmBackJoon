#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	vector<int> vec;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		vec.push_back(t);
	}
	sort(vec.begin(), vec.end());

	cout << vec[0] * vec[vec.size() - 1];

	return 0;
}