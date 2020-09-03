#include <iostream>
using namespace std;

int main() { 
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int ans = 0;
	for (int i = 5; i <= n; i*= 5) {
		ans += n / i;
	}

	cout << ans;

	return 0;
}