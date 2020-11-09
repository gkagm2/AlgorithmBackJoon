// 2016kb, 4360ms
#include <iostream>
using namespace std;

int n;
int way = 0;
int board[15]; // idx = row, value = column

void Search(int row) {
	if (row == n) {
		++way;
		return;
	}

	for (int col = 0; col < n; ++col) {
		board[row] = col;

		bool isOk = true;
		// Check 
		for (int j = 0; j < row; ++j) {
			if (board[row] == board[j] || row - j == abs(board[row] - board[j])) {
				isOk = false;
				break;
			}
		}

		if (isOk) {
			Search(row + 1);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	Search(0);
	cout << way;
	return 0;
}
