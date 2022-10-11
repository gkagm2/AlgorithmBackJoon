#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b, c, d;

	
	while (1) {
		cin >> a >> b >> c >> d;

		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;


		int minBorn = min(a, b);
		int maxBorn = max(a, b);
		int minDeath = min(c, d);
		int maxDeath = max(c, d);

		cout << minDeath - maxBorn << " ";
		cout << maxDeath - minBorn << "\n";
	}

	return 0;
}