#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	int h, w, n;
	int a, b;

	cin >> t;

	while (t--) {
		cin >> h >> w >> n;

		if (n % h == 0) {
			b = n / h;
			a = h;
		}
		else {
			a = n % h;
			b = n / h + 1;
		}
			
		cout << a * 100 + b << '\n';
	}

	return 0;
}