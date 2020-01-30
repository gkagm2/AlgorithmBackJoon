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

// 산술평균
inline int ArithmeticMean(int arr[], int cnt) {
	double sum = 0;
	for (int i = 0; i < cnt; ++i) {
		sum += arr[i];
	}

	return round(sum / cnt); // 반올림
}

// 중앙값
inline int Median(int arr[], int cnt) {
	return arr[cnt / 2];
}

// 최빈값
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
		if (visitiedArr[maxVisitedIdx] < visitiedArr[i]) { // 방문한 배열의 인덱스중에 이전에 방문했던 인덱스의 카운트보다 높으면
			maxVisitedIdx = i; // 카운트가 가장 높은 인덱스 번호를 저장한다.
			vec.clear(); // 비어둔다.
			vec.push_back(i - 4000); // 값으로 변환하여 벡터에 넣는다.
		}
		else if (visitiedArr[maxVisitedIdx] == visitiedArr[i]) { // 이전에 방문했던 카운트가 높은 인덱스와 지금 방문한 인덱스의 카운트가 같다면
			vec.push_back(i - 4000); // 값으로 변환하여 벡터에 넣는다.
		}
	}
	sort(vec.begin(), vec.end());

	if (vec.size() > 1) {
		return vec.at(1);
	}
	return vec.at(0);
}

// 범위
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

	// 산술평균
	cout << ArithmeticMean(arr, cnt) << '\n';

	// 중앙값
	cout << Median(arr, cnt) << '\n';

	// 최빈값
	cout << Mode(arr, cnt) << '\n';
	
	// 범위
	cout << Range(arr, cnt);

	return 0;
}