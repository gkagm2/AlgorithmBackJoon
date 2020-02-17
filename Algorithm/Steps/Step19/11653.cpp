#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	int a;
	cin >> num;

	while (true) {
		for (int i = 2; i <= num; ++i) {
			if (num % i == 0) {
				cout << i << '\n';
				num = num / i;
				break;
			}
		}
		if (num < 2)
			break;
	}

	return 0;
}