#include <iostream>
using namespace std;

int maxY, maxX;

inline void Input(int** matrix) {
	for (int i = 0; i < maxY; ++i) {
		for (int j = 0; j < maxX; ++j) {
			cin >> matrix[i][j];
		}
	}
}

inline void Print(int** matrix) {
	for (int i = 0; i < maxY; ++i) {
		for (int j = 0; j < maxX; ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> maxY >> maxX >> cnt;

	// 메모리 할당 선언
	int** matrix = new int* [maxY];
	for (int i = 0; i < maxY; ++i) {
		matrix[i] = new int[maxX];
	}

	Input(matrix);
	cout << '\n';

	Print(matrix);



	// 메모리 해제
	for (int i = 0; i < maxY; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
