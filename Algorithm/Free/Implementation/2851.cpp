#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
#define MAXCNT 10
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int mushroom[MAXCNT];

	for (int i = 0; i < MAXCNT; ++i) {
		int input;
		cin >> input;
		mushroom[i] = input;
	}

	int sum = INT_MAX;
	int gap = INT_MAX;
	int curGap;
	int curSum = 0;

	for (int j = 0; j < MAXCNT; ++j) {
		curSum += mushroom[j];
		curGap = abs(curSum - 100);
	
		if (curGap <= gap) {
			sum = curSum;
			gap = curGap;
		}
	}

	cout << sum;

	return 0;
}