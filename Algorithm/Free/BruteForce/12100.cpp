#include <iostream>
#include<string.h>
#include <algorithm>
#include <queue>
using namespace std;

int board[20][20];
int orgBoard[20][20];
bool CheckAlreadyCombine[20][20];
int n;
int g_max;

void InitCombineCheck() {
	for (int i = 0; i < n; ++i) {
		memset(CheckAlreadyCombine[i], false, sizeof(bool) * n);
	}
}

void Rotate() // rotate 90 degree CW
{
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - 1 - i; j++)
		{
			int Top = board[i][j]; // Top
			board[i][j] = board[n - 1 - j][i]; // top < left
			board[n - 1 - j][i] = board[n - 1 - i][n - 1 - j]; // left < bottom
			board[n - 1 - i][n - 1 - j] = board[j][n - 1 - i]; // bottom < right
			board[j][n - 1 - i] = Top; // right < Top
		}
	}
}

void Compression() {
	// left compression
	int fstIdx =0;
	for (int y = 0; y < n; ++y) {
		fstIdx = 0;
		for (int i = 1; i < n; ++i) {
			if (board[y][i] == 0) {
				CheckAlreadyCombine[y][i] = true;
				continue;
			}
			if (CheckAlreadyCombine[y][fstIdx] == true) {
				int tIdx = 0;
				while (tIdx < n) {
					if (CheckAlreadyCombine[y][tIdx] == false)
						break;
					++tIdx;
				}
				fstIdx = tIdx;
			}
			if (fstIdx == i)
				continue;
			if (board[y][fstIdx] == board[y][i]) {
				board[y][fstIdx] *= 2;
				board[y][i] = 0;
				CheckAlreadyCombine[y][fstIdx] = true;
				CheckAlreadyCombine[y][i] = true;
			}
			else {
				CheckAlreadyCombine[y][fstIdx] = true;
				fstIdx = i;
			}
		}
		InitCombineCheck();
		fstIdx = 0;
	}
	InitCombineCheck();

	// move ele to emp space
	queue<int > empIdxQ;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (board[y][x] == 0) {
				empIdxQ.push(x);
			}
			else {
				if (!empIdxQ.empty()) {
					int idx = empIdxQ.front();
					empIdxQ.pop();
					board[y][idx] = board[y][x];
					board[y][x] = 0;
					empIdxQ.push(x);
				}
			}
		}
		while (!empIdxQ.empty())
			empIdxQ.pop();
	}
}

void Left() {
	Compression();
}

void Right() {
	Rotate();
	Rotate();
	Compression();
	Rotate();
	Rotate();
}

void Up() {
	Rotate();
	Rotate();
	Rotate();
	Compression();
	Rotate();
}

void Down() {
	Rotate();
	Compression();
	Rotate();
	Rotate();
	Rotate();
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	void (*fp[4])() = { Left, Right, Up, Down };
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			orgBoard[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				for (int m = 0; m < 4; ++m) {
					for (int v = 0; v < 4; ++v) {
						(*fp[i])();
						(*fp[j])();
						(*fp[k])();
						(*fp[m])();
						(*fp[v])();

						// get max
						int iMax = 0;
						for (int i = 0; i < n; ++i) {
							for (int j = 0; j < n; ++j) {
								iMax = max(board[i][j], iMax);
							}
						}
						if (iMax > g_max)
							g_max = iMax;

						// board reset
						for (int z = 0; z < n; ++z) {
							for (int q = 0; q < n; ++q) {
								board[z][q] = orgBoard[z][q];
							}
						}
					}
					
				}
			}
		}
	}	
	
	cout << g_max;
	
	return 0;
}