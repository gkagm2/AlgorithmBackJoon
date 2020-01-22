#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, w, h;
	int minX, minY;
	cin >> x >> y >> w >> h;
	
	minX = w - x > x ? x : w - x;
	minY = h - y > y ? y : h - y;
	cout << (minX > minY ? minY : minX);

	return 0;
}