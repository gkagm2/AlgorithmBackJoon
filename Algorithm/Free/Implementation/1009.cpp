#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	int a, b;
	cin >> t;

	for (int x = 0; x < t; ++x) {
		cin >> a >> b;

		int answer = 1;
		for (int i = 0; i < b; ++i) {
			answer = (answer * a) % 10;
		}

		if (answer % 10 == 0)
			cout << 10 << "\n";
		else
			cout << answer % 10 << "\n";
	}

	return 0;
}