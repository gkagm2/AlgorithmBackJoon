#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int iStation;

	int mostPeopleCnt = 0;
	int curPeopleCnt = 0;
	for (int i = 0; i < 4; ++i) {
		int in, out;
		cin >> out >> in;

		if (curPeopleCnt > mostPeopleCnt)
			mostPeopleCnt = curPeopleCnt;

		curPeopleCnt -= out;
		curPeopleCnt += in;
	}

	cout << mostPeopleCnt;

	return 0;
}