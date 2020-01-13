#include <iostream>
using namespace std;

int main() {
	int hour, minute;
	int tempMinute;
	cin >> hour;
	cin >> minute;

	tempMinute = hour * 60 + minute - 45;
	hour = tempMinute / 60;
	minute = tempMinute % 60;
	if (minute < 0) {
		hour = 23;
		minute = 60 + minute;
	}

	cout << hour << " " << minute;
	return 0;
}