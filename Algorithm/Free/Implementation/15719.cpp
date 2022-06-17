#include <iostream>
using namespace std;

int pMap[10000000] = { 0, };

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int iOverlapNum;
	int iInputCnt;
	int iInput;

	cin >> iInputCnt;

	for (int i = 0; i < iInputCnt; ++i) {
		cin >> iInput;

		if (pMap[iInput] != 0) {
			iOverlapNum = iInput;
			break;
		}
		else
			pMap[iInput] = 1;
	}

	cout << iOverlapNum;

	return 0;
}