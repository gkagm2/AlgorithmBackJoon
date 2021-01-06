#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j)
			cout << " ";
		for (int k = n - i; k > 0; --k)
			cout << "*";
		cout << "\n";
	}

	return 0;
}