#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int threeB = 0;
	int fiveB = 0;
	cin >> n;

	fiveB = n / 5;
	threeB = n % 5 / 3;

	while (true) {
		if (fiveB < 0) {
			cout << -1;
			break;
		}
		if (fiveB * 5 + threeB * 3 == n) {
			cout << fiveB + threeB;
			break;
		}
		--fiveB;
		threeB = (n - fiveB * 5) / 3;
		
	}
	return 0;
}