#include <iostream>
using namespace std;

int arr[100000];
int n;

void QuickSort(int ele[], int left, int right) {
	int pivot = ele[(left + right) / 2];
	int l = left;
	int r = right;

	while (l < r) {
		while (ele[l] < pivot) {
			++l;
		}
		while (ele[r] > pivot) {
			--r;
		}
		if (l <= r) {
			if (l < r) {
				int temp = ele[l];
				ele[l] = ele[r];
				ele[r] = temp;
			}
			++l;
			--r;
		}	
	}
	if (left < r)
		QuickSort(ele, left, r);
	if (right > l)
		QuickSort(ele, l, right);

}

int BinarySearch(int ele[], int num) {
	bool isFind = false;
	int left = 0;
	int right = n;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (ele[mid] == num) {
			isFind = true;
			break;
		}

		if (num > ele[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return isFind == true ? 1 : 0;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	QuickSort(arr, 0, n - 1);

	int fn;
	cin >> fn;
	for (int i = 0; i < fn; ++i) {
		int findNum;
		cin >> findNum;
		cout << BinarySearch(arr, findNum) << "\n";
	}

	return 0;
}