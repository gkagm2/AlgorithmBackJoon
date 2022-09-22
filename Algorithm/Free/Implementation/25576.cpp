#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	vector<vector<int>> vecList;

	vecList.resize(n);
	for (int i = 0; i < vecList.size(); ++i)
		vecList[i].resize(m);

	for (int i = 0; i < vecList.size(); ++i) {
		for (int j = 0; j < m; ++j) {
			int peopleCnt;
			cin >> peopleCnt;
			vecList[i][j] = peopleCnt;
		}
	}

	const int maxNum = 2000;
	int offset;
	int badBJCnt = 0;
	for (int i = 1; i < vecList.size(); ++i) {
		offset = 0;
		for (int j = 0; j < vecList[i].size(); ++j) {
			offset += abs(vecList[0][j] - vecList[i][j]);
		}
		if (offset > maxNum)
			++badBJCnt;
	}

	if (badBJCnt >= (n - 1) / 2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}