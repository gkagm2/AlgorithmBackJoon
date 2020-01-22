// 2104KB, 4ms
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 123456*2 + 1

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	bool numbers[MAX];
	memset(numbers, true, MAX); // √ ±‚»≠
	numbers[0] = numbers[1] = false;

	// case2
	for (int i = 2; i < MAX; ++i) {
		if (numbers[i] == true) {
			for (int j = 2; i * j < MAX; ++j) {
				numbers[i* j] = false;
			}
		}
	}

	int input, primeCount;
	while (true) {
		cin >> input;
		if (input == 0) {
			break;
		}

		primeCount = 0;

		for (int i = input + 1; i <= input * 2; ++i) {
			if (numbers[i] == true) {
				++primeCount;
			}
		}

		cout << primeCount << '\n';
	}

	return 0;
}