#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	vector<int> vBoard;
	vector<int> vDice;

	cin >> n >> m;
	vBoard.resize(n);
	vDice.resize(m);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		vBoard[i] = num;
	}

	int curPos = 1;
	int moveCnt = 0;
	for (int i = 0; i < m; ++i)
		cin >> vDice[i];
	
	for (int i = 0; i < m; ++i) {
		curPos += vDice[i];
		++moveCnt;

		if (curPos >= n)
			break;
			
		int instNum = vBoard[curPos - 1];
		curPos += instNum;

		if (curPos >= n)
			break;
	}
	cout << moveCnt;

	return 0;
}