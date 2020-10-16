#include <iostream>
using namespace std;

int n;
int arr[128][128];
int whiteCnt = 0; // 0
int blueCnt = 0; // 1

// Divide
void Divide(int startX, int startY, int size) {
	// Check
	int color = arr[startY][startX];
	for (int y = startY; y < startY + size; ++y) {
		for (int x = startX; x < startX + size; ++x) {
			if (color != arr[y][x]) { // 같지 않다면 Divide 해줘야 한다.
				Divide(startX + size / 2, startY, size / 2);
				Divide(startX, startY, size / 2);
				Divide(startX, startY + size / 2, size / 2);
				Divide(startX + size / 2, startY + size / 2, size / 2);
				return;
			}
		}
	}
	// 같다면 더이상 할 필요가 없다.
	if (color == 0)
		++whiteCnt;
	else
		++blueCnt;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	Divide(0, 0, n);

	cout << whiteCnt << "\n";
	cout << blueCnt;

	return 0;
}