#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int guestCnt;
	int rejectionCnt = 0;

	int sit[101] = {};

	cin >> guestCnt;

	for (int i = 0; i < guestCnt; ++i) {
		int sitNum;
		cin >> sitNum;
		if (sit[sitNum] == 0)
			sit[sitNum] = 1;
		else
			++rejectionCnt;
	}

	cout << rejectionCnt;
	return 0;
}