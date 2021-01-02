#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n[3];

	cin >> n[0] >> n[1] >> n[2];

	int reward;
	if (n[0] == n[1] && n[1] == n[2])
		reward =10000 + n[0] * 1000;
	else if (n[0] == n[1])
		reward = 1000 + n[0] * 100;
	else if (n[1] == n[2])
		reward = 1000 + n[1] * 100;
	else if (n[0] == n[2])
		reward = 1000 + n[0] * 100;
	else {
		int mx = 0;
		for (int i = 0; i < 3; ++i)
			mx = max(mx, n[i]);
		reward = mx * 100;
	}

	cout << reward;

	return 0;
}