#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	const int coinFive = 5;
	const int coinTwo = 2;

	int coinCnt = 0;
	while(n > 0){	
		if (n % coinFive == 0) {
			coinCnt += n / coinFive;
			break;
		}

		n = n - coinTwo;
		++coinCnt;
		if (n < 0) {
			coinCnt = -1;
			break;
		}
	}

	cout << coinCnt;

	return 0;
}