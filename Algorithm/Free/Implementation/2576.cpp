#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int minValue = 999;
	int sum = 0;
	bool isExistOdd = false;
	for (int i = 0; i < 7; ++i) {
		int input;
		cin >> input;
		if (input % 2 != 0) {
			isExistOdd = true;
			if (minValue > input) {
				minValue = input;
			}
			sum += input;
		}

	}
	if (isExistOdd) {
		cout << sum << "\n";
		cout << minValue;
	}
	else
		cout << -1;



	return 0;
}