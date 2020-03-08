#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char board[64];

	// input
	for (int i = 0; i < 64; ++i) {
		cin >> board[i];
	}
	
	int fCnt = 0;

	// search
	for (int i = 0; i < 8; i+=2) {
		for (int j = 0; j < 8; j+=2) {
			if (board[i * 8 + j] == 'F') {
				fCnt++;
			}
		}
	}
	for (int i = 1; i < 8; i += 2) {
		for (int j = 1; j < 8; j += 2) {
			if (board[i * 8 + j] == 'F') {
				fCnt++;
			}
		}
	}

	cout << fCnt;

	return 0;
}