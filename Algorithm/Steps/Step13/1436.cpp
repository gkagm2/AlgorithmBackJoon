#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int seriesCnt, tempNum;
	int seriesNum = 665;

	cin >> seriesCnt;
	
	while (seriesCnt) {
		++seriesNum;
		tempNum = seriesNum;
		while (tempNum) {
			if (tempNum % 1000 == 666) {
				--seriesCnt;
				break;
			}
			tempNum /= 10;
		}
	}
	cout << seriesNum;
	
	return 0;
}