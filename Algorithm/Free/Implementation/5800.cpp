#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GetLargestGap(const vector<int>& _scores) {
	int iGap = 0;
	for (int i = 0; i < _scores.size() - 1; ++i) {
		int iCurGap = _scores[i] - _scores[i + 1];
		if (iCurGap > iGap)
			iGap = iCurGap;
	}
	return iGap;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int iClassCnt;
	vector<int> scores;

	cin >> iClassCnt;

	for (int iCurClassNum = 0; iCurClassNum < iClassCnt; ++iCurClassNum) {
		int iStudentCnt;
		cin >> iStudentCnt;

		scores.resize(iStudentCnt);
		for (int j = 0; j < iStudentCnt; ++j)
			cin >> scores[j];

		int iMin, iMax, iLargestGap;
		sort(scores.rbegin(), scores.rend()); // 내림차순 정렬
		iMin = scores[scores.size() - 1];
		iMax = scores[0];
		iLargestGap = GetLargestGap(scores);

		// Print
		cout << "Class " << iCurClassNum + 1 << "\n";
		cout << "Max " << iMax << ", Min " << iMin << ", Largest gap " << iLargestGap << "\n";
	}

	return 0;
}