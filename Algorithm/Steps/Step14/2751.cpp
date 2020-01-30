// 5768kb, 308ms
#include <iostream>
using namespace std;

void Swap(int *a, int*b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort(int arr[], int left, int right) {
	int l = left, r = right;
	int pivot = arr[(left + right) / 2];

	while (l < r) {
		while (arr[l] < pivot)
			++l;
		while (arr[r] > pivot)
			--r;
		if (l <= r) {
			if (l < r) {
				Swap(&arr[l], &arr[r]);
			}
			++l;
			--r;
		}
	}
	if (left < r)
		QuickSort(arr, left, r);
	if (right > l)
		QuickSort(arr, l, right);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int inputArr[1000000];
	int cnt;

	cin >> cnt;
	for (int i = 0; i < cnt; ++i) {
		cin >> inputArr[i];
	}

	QuickSort(inputArr, 0, cnt - 1);
	for (int i = 0; i < cnt; ++i) {
		cout << inputArr[i] << '\n';
	}
	return 0;
}

// used sort function 5892kb, 280ms

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	int cnt;
//	cin >> cnt;
//
//	int *inputArr = new int[cnt];
//
//	for (int i = 0; i < cnt; ++i) {
//		cin >> inputArr[i];
//	}
//
//	sort(inputArr, inputArr + cnt);
//
//	for (int i = 0; i < cnt; ++i) {
//		cout << inputArr[i] << '\n';
//	}
//	return 0;
//}