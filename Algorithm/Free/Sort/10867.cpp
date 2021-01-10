#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	set<int> s;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t; 
		s.insert(t);
	}

	for (auto x : s) {
		cout << x << " ";
	}

	return 0;
}