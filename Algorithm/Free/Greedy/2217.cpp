#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		int vv = vec[i] * (n - i);
		maxNum = max(maxNum, vv);
	}

	cout << maxNum << endl;

	return 0;
}