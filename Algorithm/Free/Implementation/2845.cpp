#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int l, p, h[5];

	cin >> l >> p;

	for (int i = 0; i < 5; ++i) {
		cin >> h[i];
		cout << h[i] - l * p << " ";
	}

	return 0;
}