// Bottom up (loop)
/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// Memoization
int arr[1000001];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	memset(arr, 0, sizeof(int) * (n+1));
	arr[1] = 0;
	for (int i = 2; i <= n; ++i) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
	}
	
	cout << arr[n];
	return 0;
}
*/


// Top down  (recursive)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// Memoization
int arr[1000001];

int go(int n) {
	if (n == 1) return 0;
	if (arr[n] > 0) return arr[n];
	arr[n] = go(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = go(n / 2) + 1;
		if (arr[n] > temp) arr[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = go(n / 3) + 1;
		if (arr[n] > temp) arr[n] = temp;
	}
	return arr[n];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	memset(arr, 0, sizeof(int) * (n + 1));
	cout << go(n);

	return 0;
}