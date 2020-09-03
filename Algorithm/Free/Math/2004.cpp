#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	long long m, n;
	long long two = 0, five = 0;

	cin >> n >> m;
	// n! / (n - m)! * m!

	// n!
	for (long long i = 2; i<= n; i *=2 ) {
		two += n / i;
	}

	// (n - m)!
	for (long long i = 2; i <= n - m; i *= 2) {
		two -= (n - m) / i;
	}

	// m!
	for (long long i = 2; i <= m; i *= 2) {
		two -= m / i;
	}
	
	// n!
	for (long long i = 5; i <= n; i *= 5) {
		five += n / i;
	}

	// (n - m)!
	for (long long i = 5; i <= n - m; i *= 5) {
		five -= (n - m) / i;
	}

	// m!
	for (long long i = 5; i <= m; i *= 5) {
		five -= m / i;
	}

	cout << min(two, five);
		
	return 0;
}