#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int line = 0; line < n; ++line) {
		for (int star = 0; star <= line; ++star) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}