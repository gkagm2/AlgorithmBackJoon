#include <iostream>
using namespace std;
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int h, m;
	int rTime;
	cin >> h >> m;
	cin >> rTime;

	int resTime = h * 60 + m + rTime;

	int hour = resTime / 60;
	hour = hour % 24;
	int min = resTime % 60;

	cout << hour << " " << min;

	return 0;
}