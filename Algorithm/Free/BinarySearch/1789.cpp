#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	long long n = 1, s;
	long long sum = 0;
	cin >> s;
	while (1) {
		sum += n;
		if (sum == s)
			break;
		if (sum > s) {
			--n;
			break;
		}
		++n;
	}
	cout << n;

	return 0;
}