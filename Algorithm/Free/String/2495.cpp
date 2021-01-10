#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int cnt = 3;

	char preNum;
	int maxCnt = 1;
	int tempCnt = 0;
	while (cnt--) {
		maxCnt = 1;
		string t;
		cin >> t;
		preNum = t[0];
		tempCnt = 1;
		for (int i = 1; i < t.size(); ++i) {
			if (t[i] == preNum) {
				++tempCnt;
				if (maxCnt < tempCnt)
					maxCnt = tempCnt;
			}
			else
				tempCnt = 1;
			preNum = t[i];
		}
		cout << maxCnt << "\n";
	}

	return 0;
}