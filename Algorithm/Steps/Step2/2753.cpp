#include <iostream>
using namespace std;

int main() {
	int year;
	cin >> year;

	// 윤년일 경우 1, 윤년이 아닐경우 0
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		cout << "1";
	}
	else {
		cout << "0";
	}

	return 0;
}