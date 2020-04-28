#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;

	cin >> cnt;
	
	int axisCnt, q1Cnt, q2Cnt, q3Cnt, q4Cnt;
	axisCnt = q1Cnt = q2Cnt = q3Cnt = q4Cnt = 0;
	for (int i = 0; i < cnt; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == 0 || y == 0) {
			++axisCnt;
		}
		else if (x > 0 && y > 0) {
			++q1Cnt;
		}
		else if (x < 0 && y > 0) {
			++q2Cnt;
		}
		else if (x < 0 && y < 0) {
			++q3Cnt;
		}
		else if (x > 0 && y < 0) {
			++q4Cnt;
		}
	}

	cout << "Q1: " << q1Cnt << '\n';
	cout << "Q2: " << q2Cnt << '\n';
	cout << "Q3: " << q3Cnt << '\n';
	cout << "Q4: " << q4Cnt << '\n';
	cout << "AXIS: " << axisCnt;

	return 0;
}
