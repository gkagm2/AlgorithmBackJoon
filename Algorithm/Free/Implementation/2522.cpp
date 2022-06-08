#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	for (int i = 1; i <= cnt; ++i) {
		for (int s = cnt - i; s > 0; --s)
			cout << " ";

		for (int k = 0; k < i; ++k)
			cout << "*";
		cout << "\n";
	}

	for (int i = 1; i < cnt; ++i) {
		for (int k = 0; k < i; ++k)
			cout << " ";
		for (int s = cnt - i; s > 0; --s)
			cout << "*";
		cout << "\n";
	}

	return 0;
}