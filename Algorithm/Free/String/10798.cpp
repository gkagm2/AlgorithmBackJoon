#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	char board[5][16] = { 0 };

	for (int i = 0; i < 5; ++i) {
		cin >> board[i];
	}

	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 5; ++j) {
			if(board[j][i] != '\0')
				cout << board[j][i];
		}
	}

	return 0;
}