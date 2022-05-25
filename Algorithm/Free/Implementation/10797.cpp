#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);


	int day;

	cin >> day;

	int car[10] = {};

	for (int i = 0; i < 5; i++)
		cin >> car[i];

	int carCnt = 0;
	for (int i = 0; i < 5; ++i) {
		if (car[i] == day)
			++carCnt;
	}

	cout << carCnt;

	return 0;
}