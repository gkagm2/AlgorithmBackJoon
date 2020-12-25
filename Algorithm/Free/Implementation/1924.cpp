#include <iostream>
#include <string>
using namespace std;

int arr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

string str[] = {"MON","TUE","WED","THU","FRI","SAT", "SUN"};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int m, d;

	cin >> m >> d;

	int dayCnt =0;
	for (int i = 0; i < m - 1; ++i) {
		dayCnt += arr[i];
	}

	dayCnt += d;
	int dd = (dayCnt % 7) - 1;
	if (dd < 0)
		dd = 6;
	cout << str[dd];

	return 0;
}