#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;;

#define MAX_NUM 8001

void Swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort(int arr[], int left, int right) {
	int l = left;
	int r = right;
	int pivot = arr[(l + r) / 2];

	while (l < r) {
		while (arr[l] < pivot) {
			++l;
		}
		while (arr[r] > pivot) {
			--r;
		}

		if (l <= r) {
			if (l < r) {
				Swap(&arr[l], &arr[r]);
			}
			++l;
			--r;
		}
	}

	if (l < right) {
		QuickSort(arr, l, right);
	}
	if (r > left) {
		QuickSort(arr, left, r);
	}
}

// ������
inline int ArithmeticMean(int arr[], int cnt) {
	double sum = 0;
	for (int i = 0; i < cnt; ++i) {
		sum += arr[i];
	}

	return round(sum / cnt); // �ݿø�
}

// �߾Ӱ�
inline int Median(int arr[], int cnt) {
	return arr[cnt / 2];
}

// �ֺ�
inline int Mode(int arr[], int cnt) {
	int visitiedArr[MAX_NUM];
	int HighestNum = 0;
	int maxVisitedCount = 0;
	int maxVisitedIdx = 0;

	memset(visitiedArr, 0, sizeof(visitiedArr));

	for (int i = 0; i < cnt; ++i) {
		++visitiedArr[arr[i] + 4000];
	}

	vector<int> vec;

	for (int i = 0; i < MAX_NUM; ++i) {
		if (visitiedArr[maxVisitedIdx] < visitiedArr[i]) { // �湮�� �迭�� �ε����߿� ������ �湮�ߴ� �ε����� ī��Ʈ���� ������
			maxVisitedIdx = i; // ī��Ʈ�� ���� ���� �ε��� ��ȣ�� �����Ѵ�.
			vec.clear(); // ���д�.
			vec.push_back(i - 4000); // ������ ��ȯ�Ͽ� ���Ϳ� �ִ´�.
		}
		else if (visitiedArr[maxVisitedIdx] == visitiedArr[i]) { // ������ �湮�ߴ� ī��Ʈ�� ���� �ε����� ���� �湮�� �ε����� ī��Ʈ�� ���ٸ�
			vec.push_back(i - 4000); // ������ ��ȯ�Ͽ� ���Ϳ� �ִ´�.
		}
	}
	sort(vec.begin(), vec.end());

	if (vec.size() > 1) {
		return vec.at(1);
	}
	return vec.at(0);
}

// ����
inline int Range(int arr[], int cnt) {
	return arr[cnt - 1] - arr[0];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	int *arr = new int[cnt];
	
	for (int i = 0; i < cnt; ++i) {
		cin >> arr[i];
	}

	QuickSort(arr, 0, cnt - 1);

	// ������
	cout << ArithmeticMean(arr, cnt) << '\n';

	// �߾Ӱ�
	cout << Median(arr, cnt) << '\n';

	// �ֺ�
	cout << Mode(arr, cnt) << '\n';
	
	// ����
	cout << Range(arr, cnt);

	return 0;
}