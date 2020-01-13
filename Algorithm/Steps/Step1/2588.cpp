#include <iostream>
using namespace std;
int main() {
	int a, b, tempB, count, mulValue;

	cin >> a;
	cin >> b;
	mulValue = a * b;

	tempB = b;

	for (count = 0; tempB > 0; ++count) {
		tempB /= 10;
	}

	while (count > 0) {
		cout << a * (b % 10) << endl;
		b = b / 10;
		--count;
	}

	cout << mulValue;

	return 0;
}