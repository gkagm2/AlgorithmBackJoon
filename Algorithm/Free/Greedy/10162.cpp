#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b, c;
	int t;

	cin >> t;

	if (t % 10)
		cout << -1;
	else {
		a = t / 300;
		t %= 300;
		b = t / 60;
		t %= 60;
		c = t / 10;
		cout << a << " " << b << " " << c;
	}

	return 0;
}