#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		int num;
		int minNum = 100;
		for (int j = 0; j < 7; ++j) {
			cin >> num;
			if (num % 2 == 0) {
				sum += num;
				if (minNum > num)
					minNum = num;
			}
		}
		cout << sum << " " << minNum << "\n";
	}

	return 0;
}