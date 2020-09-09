#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[9];
int nums[10];
void dfs(int idx, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		a[idx] = nums[i];
		dfs(idx + 1, n, m);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		
	}
	sort(nums, nums + n);
	dfs(0, n, m);

	return 0;
}