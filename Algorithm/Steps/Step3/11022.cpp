#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count;
	int a, b;

	cin >> count;

	for (int i = 1; i <= count; ++i) {
		cin >> a;
		cin >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << '\n';
	}

	return 0;
}