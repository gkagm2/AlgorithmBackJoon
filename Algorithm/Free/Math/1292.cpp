#include <iostream>
using namespace std;

int arr[1001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int cnt = 1;
	int tempCnt = 0;
	for (int i = 1; i < 1001; ++i) {
		if (tempCnt == cnt) {
			cnt++;
			tempCnt = 0;
		}
		arr[i] = cnt;
		++tempCnt;
	}

	int a, b;

	cin >> a >> b;

	int ans = 0;
	for (int i = a; i <= b; ++i) {
		ans += arr[i];
	}

	cout << ans;
	
	return 0;
}