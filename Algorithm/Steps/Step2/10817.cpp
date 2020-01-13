#include <iostream>
using namespace std;

void QuickSort(int arr[], int left, int right) {
	int l;
	int r;
	int pivot;
	l = left;
	r = right;
	pivot = arr[left];
	while (left < right) {
		while (arr[right] > pivot && left < right) {
			--right;
		}
		if (left != right) {
			arr[left] = arr[right];
			++left;
		}

		while (arr[left] < pivot && left < right) {
			++left;
		}
		if (left != right) {
			arr[right] = arr[left];
			--right;
		}
	}

	arr[left] = pivot;
	pivot = left;
	left = l;
	right = r;
	
	if(left < pivot) {
		QuickSort(arr, left, pivot - 1);
	}
	if (right > pivot) {
		QuickSort(arr, pivot + 1, right);
	}
}

int main() {
	int arr[3];
	int second;

	cin >> arr[0];
	cin >> arr[1];
	cin >> arr[2];
	
	QuickSort(arr, 0, 2);
	cout << arr[1];

	return 0;
}