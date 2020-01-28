#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int card[100];

	int cardCnt;
	int hitNum;

	cin >> cardCnt >> hitNum;
	for (int i = 0; i < cardCnt; ++i) {
		cin >> card[i];
	}

	int sum = 0;
	for (int i = 0; i < cardCnt - 2; ++i) {
		for (int j = i + 1; j < cardCnt - 1; ++j) {
			for (int k = j + 1; k < cardCnt; ++k) {
				int num = card[i] + card[j] + card[k];
				if (num > sum && num <= hitNum) {
					sum = num;
					if (sum == hitNum) {
						goto endFind;
					}
				}
			}
		}
	}
	endFind:
	cout << sum;

	return 0;
}