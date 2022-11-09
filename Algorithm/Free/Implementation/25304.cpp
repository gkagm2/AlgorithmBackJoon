#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int money;
	cin >> money;

	int cnt;
	cin >> cnt;

	int acc = 0;
	for (int i = 0; i < cnt; ++i) {
		int m, num;
		cin >> m >> num;

		acc += m * num;
	}

	if (money == acc)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}