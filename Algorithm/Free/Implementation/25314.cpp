#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int m = n / 4;
	int e = n % 4;

	for (int i = 0; i < m; ++i)
		cout << "long ";
	if (e != 0) {
		cout << "long ";
	}

	cout << "int";

	return 0;
}