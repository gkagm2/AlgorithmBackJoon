#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	int range = 1;
	int roomNumber= 1;
	int temp = 1;

	cin >> num;

	while (range < num) {

		temp = 6 * (roomNumber);
		range += temp;
		++roomNumber;
	}

	cout << roomNumber;

	return 0;
}