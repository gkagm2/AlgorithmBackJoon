#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, l;

	cin >> n >> m >> l;

	int human[51] = {};
	int curNum = 1;
	int ballCnt = 0;

	++human[curNum];

	while (true) {
		if (human[curNum] >= m) {
			// game over
			break;
		}
		
		// 홀수면 시계방향
		if (human[curNum] % 2 != 0)
			curNum += l;
		// 짝수면 반시계방향
		else
			curNum -= l;

		if (curNum > n)
			curNum = curNum % n;
		else if (curNum <= 0)
			curNum += n;

		++human[curNum];
		++ballCnt;
	}

	cout << ballCnt;
	
	return 0;
}