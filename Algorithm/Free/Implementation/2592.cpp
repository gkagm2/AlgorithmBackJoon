#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int average = 0;
	int sum = 0;
	int num[1001] = {};

	for (int i = 0; i < 10; ++i) {
		int input;
		cin >> input;
		++num[input];
		sum += input;
	}

	int maxidxCnt = 0;
	int maxNum = 0;
	for (int i = 0; i < 1000; i += 10) {
		if (maxidxCnt < num[i]) {
			maxidxCnt = num[i];
			maxNum = i;
		}
	}

	average = sum / 10;

	cout << average << "\n";
	cout << maxNum;

	return 0;
}