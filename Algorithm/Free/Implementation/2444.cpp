#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	// up
	for (int i = 0; i < n; ++i) {
		for (int j = n - i - 1; j > 0; --j)
			cout << " ";
		for (int k = 0; k < 2 * (i + 1) - 1; ++k)
			cout << "*";
		cout << "\n";
	}

	// down
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j)
			cout << " ";
		for (int k = (n - i) * 2 - 1; k > 0; --k)
			cout << "*";
		cout << "\n";
	}

	return 0;
}