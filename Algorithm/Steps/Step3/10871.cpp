#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, x;
	int a;

	cin >> n >> x;

	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a < x)
			cout << a << " ";
	}

	return 0;
}