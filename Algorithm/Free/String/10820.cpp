#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int uCCnt, lCCnt, numCnt, spaceCnt;
	uCCnt = lCCnt = numCnt = spaceCnt = 0;

	int n = 100;
	while (n--) {
		getline(cin, str);
		if (str.length() == 0)
			break;

		for (int i = 0; i < str.length(); ++i) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				++uCCnt;
			}
			else if (str[i] >= 'a' && str[i] <= 'z') {
				++lCCnt;
			}
			else if (str[i] >= '0' && str[i] <= '9') {
				++numCnt;
			}
			else if (str[i] == ' ') {
				++spaceCnt;
			}
		}

		cout << lCCnt << ' ' << uCCnt << ' ' << numCnt << ' ' << spaceCnt << '\n';
		uCCnt = lCCnt = numCnt = spaceCnt = 0;
	}

	return 0;
}
