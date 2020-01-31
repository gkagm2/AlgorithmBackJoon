#include <iostream>
using namespace std;

int cnt;

void Merge(int arr[], int low, int middle, int high) {
	int *sorted = new int[cnt];
	int l, k;
	l = k = low;
	int mid = middle + 1;

	while (l <= middle && mid <= high) {
		// 내림차순
		if (arr[l] > arr[mid]) {
			sorted[k++] = arr[l++]; 
		}
		else {
			sorted[k++] = arr[mid++];
		}
	}

	if (l > middle) {
		for (int i = mid; i <= high; ++i) {
			sorted[k++] = arr[i];
		}
	}
	else {
		for (int i = l; i <= middle; ++i) {
			sorted[k++] = arr[i];
		}
	}

	for (int i = low; i <= high; ++i) {
		arr[i] = sorted[i];
	}
	delete[]sorted;
}

void MergeSort(int arr[], int low, int high) {

	if (low < high) {
		int middle = (low + high) / 2;
		MergeSort(arr, low, middle);
		MergeSort(arr, middle + 1, high);
		Merge(arr, low, middle, high);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int inputNum;
	cin >> inputNum;

	int numArr[10];
	cnt = 0;
	while (inputNum) {
		numArr[cnt] = inputNum % 10;
		inputNum /= 10;
		++cnt;
	}

	MergeSort(numArr, 0, cnt - 1);
	for (int i = 0; i < cnt; ++i) {
		cout << numArr[i];
	}

	return 0;
}