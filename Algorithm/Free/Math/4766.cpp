#include <iostream>
using namespace std;
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	float preTemp = -999;
	float curTemp = 0;

	cout << fixed;
	cout.precision(2);

	while (cin >> curTemp) {
		if (curTemp == 999)
			break;
		if (preTemp == -999) {
			preTemp = curTemp;
			continue;
		}

		cout << curTemp - preTemp << "\n";
		preTemp = curTemp;
	}

	return 0;
}