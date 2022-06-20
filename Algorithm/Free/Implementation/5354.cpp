#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int cnt;
		cin >> cnt;

		for (int y = 0; y < cnt; ++y) {
			for (int x = 0; x < cnt; ++x) {
				if (y == 0 || y == cnt - 1)
					cout << "#";
				else {
					if (x == 0 || x == cnt - 1)
						cout << "#";
					else
						cout << "J";
				}
			}
			cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}