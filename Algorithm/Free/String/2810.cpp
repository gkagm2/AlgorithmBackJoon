#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	char s[51];

	cin >> n;
	cin >> s;
	int seatCnt = 1;
	int lCnt = 0;
	
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'S')
			++seatCnt;
		else {
			++lCnt;
			if (lCnt == 2) {
				++seatCnt;
				lCnt = 0;
			}
		}
	}
	if (lCnt > 0)
		++seatCnt;

	seatCnt = seatCnt < n ? seatCnt : n;
	cout << seatCnt;

	return 0;
}