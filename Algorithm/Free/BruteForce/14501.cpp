#include <iostream>
#include <vector>
using namespace std;

int t[15];
int p[15];
int ans = 0;
int n;

void func(int day, int sum) {
	if (day > n)
		return;
	if (day == n) {
		if (sum > ans)
			ans = sum;
		return;
	}

	func(day + 1, sum);
	func(day + t[day], sum + p[day]);
}

void func2(int day, int sum) {
	vector<int> temp;

	while (true) {
		if (day > n)
			break;
		if (day == n)
			if (sum > ans)
				ans = sum;
		
	}
}



int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i]>> p[i];
	}

	func(0, 0);
	cout << ans;

	return 0;
}