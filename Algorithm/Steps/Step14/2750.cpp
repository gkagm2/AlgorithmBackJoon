#include <iostream>
using namespace std;

void InsertionSort(int elements[], int cnt) {
	int i, j, key;

	for (i = 1; i < cnt; ++i) {
		key = elements[i];
		for (j = i - 1; j >= 0 && elements[j] > key; --j) {
			elements[j + 1] = elements[j];
		}
		elements[j + 1] = key;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int inputArr[1000];
	int cnt;

	cin >> cnt;
	for (int i = 0; i < cnt; ++i) {
		cin >> inputArr[i];
	}
	InsertionSort(inputArr, cnt);
	for (int i = 0; i < cnt; ++i) {
		cout << inputArr[i] << '\n';
	}
	return 0;
}