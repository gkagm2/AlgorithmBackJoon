// minimum heap
#include <iostream>
using namespace std;

class Heap {
private:
	int arr[100001];
	int size;

private:
	void Swap(int *a, int *b) {
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
public:
	Heap() : size(0) {}
	void Insert(int data) {
		++size;

		arr[size] = data;
		int idx = size;
		while (arr[idx / 2] > arr[idx]) {
			Swap(&arr[idx / 2], &arr[idx]);
			idx = idx / 2;
		}
	}
	int Top() {
		if (size == 0) {
			return 0;
		}
		return arr[1];
	}
	void Pop() {
		if (size == 0) {
			return;
		}
		Swap(&arr[size], &arr[1]);

		--size;
		
		int idx = 1;
		int childIdx;
		while (idx * 2 <= size) {
			if (arr[idx * 2] < arr[idx * 2 + 1] || idx * 2 + 1 > size) { // 왼쪽 자식이 오른쪽 자식보다 작으면
				childIdx = idx * 2;
			}
			else {
				childIdx = idx * 2 + 1;
			}

			if (arr[idx] < arr[childIdx]) {
				break;
			}

			Swap(&arr[idx], &arr[childIdx]);
			idx = childIdx;
		}
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Heap heap;
	int n;
	cin >> n;

	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (num == 0) {
			cout << heap.Top() <<'\n';
			heap.Pop();
		}
		else
		{
			heap.Insert(num);
		}
	}

	return 0;
}