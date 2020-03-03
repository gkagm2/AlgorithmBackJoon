#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

void QuickSort(int ele[], int left, int right) {
	int l = left;
	int r = right;
	int pivot = ele[(left + r) / 2];

	while (l < r) {
		while (ele[l] < pivot) {
			++l;
		}
		while (ele[r] > pivot) {
			--r;
		}

		if (l <= r) {
			if (l < r) {
				Swap(ele[l], ele[r]);
			}
			++l;
			--r;
		}
	}

	if (r > left) {
		QuickSort(ele, left, r);
	}
	if (l < right) {
		QuickSort(ele, l, right);
	}
}

int sorted[50];
void Merge(int ele[], int left, int mid, int right) {
	int l, k, m;
	l = k = left;
	m = mid + 1;

	while (l <= mid && m <= right) {
		if (ele[l] <= ele[m])
			sorted[k++] = ele[l++];
		else {
			sorted[k++] = ele[m++];
		}
	}

	if (l > mid) {
		for (int i = m; i <= right; ++i) {
			sorted[k++] = ele[i];
		}
	} 
	else{
		for (int i = l; i <= mid; ++i) {
			sorted[k++] = ele[i];
		}
	}

	for(int i = left; i <= right; ++i) {
		ele[i] = sorted[i];
	}
}

void MergeSort(int ele[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(ele, left, mid);
		MergeSort(ele, mid + 1, right);
		Merge(ele, left, mid, right);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a[50];
	int b[50];

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	QuickSort(a, 0, n - 1);
	MergeSort(b, 0, n - 1);

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (a[i] * b[n - 1 - i]);
	}
	cout << sum;

	return 0;
}