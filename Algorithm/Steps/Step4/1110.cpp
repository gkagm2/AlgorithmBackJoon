#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int inputI, startI;
	int frontI, backI;
	int count = 0;

	cin >> inputI;
	startI = inputI;

	do {
		++count;

		frontI = startI / 10;
		backI = startI % 10;
		frontI = frontI + backI;
		frontI = frontI % 10;
		startI = backI * 10 + frontI;

	} while (inputI != startI);
	
	cout << count;

	return 0;
}