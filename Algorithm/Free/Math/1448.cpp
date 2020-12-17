#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	
	bool isOk = false;
	for (int maxIdx = v.size() - 1; maxIdx >= 2; maxIdx--) {
		
		int i = maxIdx - 2;
		while (i >= 0) {
			if (v[maxIdx] < v[i] + v[i + 1]) {
				cout << v[maxIdx] + v[i] + v[i + 1];
				isOk = true;
				break;
			}
			--i;
		}
		if (isOk) break;
			
	}
	if (!isOk)
		cout << -1;

	return 0;
}