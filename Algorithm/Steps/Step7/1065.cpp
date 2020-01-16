#include <iostream>
using namespace std;

#define MAX_ARR 3

inline int GetHansu(int number) {
	int arr[MAX_ARR];

	if (number < 100) {
		return 1;
	}

	int tempNumber;
	int i = 0;
	
	while (number != 0) {
		arr[i] = number % 10;
		number = number / 10;
		++i;
	}

	int d = arr[0] - arr[1];
	for (int j = 0; j < i - 1; ++j) {
		if (arr[j] - arr[j + 1] != d) {
			return 0;
		}
	}
	return 1;
}

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	
	int number;

	cin >> number;
	int count = 0;
	for (int i = 1; i <= number; ++i) {
		count += GetHansu(i);
	}

	cout << count << '\n';
	return 0;
}