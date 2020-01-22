#include <iostream>
using namespace std;

inline bool IsPrime(const int &num) {
	if (num == 1)
		return false;

	bool isPrimeNum = true;
	for (int i = 2; i < num / 2 + 1; ++i) {
		if (num % i == 0) {
			isPrimeNum = false;
			break;
		}
	}
	return isPrimeNum;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int sum = 0;

	int min, max, minPrime = 10001;
	cin >> min >> max;
	for (int i = min; i <= max; ++i) {
		if (IsPrime(i)) {
			sum += i;
			if (minPrime > i) {
				minPrime = i;
			}
		}
	}

	if (minPrime == 10001) {
		cout << "-1\n";
	}
	else {
		cout << sum << '\n';
		cout << minPrime;
	}

	return 0;
}