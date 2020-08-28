#include <iostream>
#include <cstring>
using namespace std;
int arr[1001];

// Topdown
int go(int n) {
	if (n == 0 || n == 1) {
		arr[n] = 1;
		return arr[n];
	}
	
	if (arr[n] > 0) {
		return arr[n];
	}
	arr[n] = go(n - 1) + go(n - 2);
	arr[n] %= 10007;
	return arr[n];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	memset(arr, 0, sizeof(int) * 1001);

	int n;
	cin >> n;
	cout << go(n);
	return 0;
}

/*
// Bottom up
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	memset(arr, 0, sizeof(int) * 1000);

	int n;
	cin >> n;
	
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= n; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 10007;
	}

	cout << arr[n];
	return 0;
}
*/