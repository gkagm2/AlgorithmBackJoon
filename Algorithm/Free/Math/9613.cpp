#include<iostream>
using namespace std;

int arr[100];

inline int GCD(int a, int b) {
	int temp, n;

	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	long long sum = 0;

	cin >> cnt;
	while(cnt--) {
		int arrCnt;
		cin >> arrCnt;
		for (int i = 0; i < arrCnt; ++i) {
			cin >> arr[i];
		}

		for (int i = 0; i < arrCnt- 1; ++i) {
			for (int j = i + 1; j < arrCnt; ++j) {
				sum += GCD(arr[i], arr[j]);
			}
		}
		
		cout << sum << '\n';
		sum = 0;
	}

	return 0;
}