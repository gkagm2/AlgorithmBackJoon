#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// memorization
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