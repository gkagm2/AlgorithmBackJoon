#include <iostream>
using namespace std;

// O(root of n)
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, count = 0;
	int num;
	bool isPrimeNum;

	cin >> n;

	while (n--) {
		isPrimeNum = true;
		cin >> num;
		
		if (num < 2) {
			isPrimeNum = false;
		}
		else {
			for (int i = 2; i *i <= num; ++i) {
				if (num % i == 0) {
					isPrimeNum = false;
					break;
				}
			}
		}

		if (isPrimeNum)
			++count;
	}
	cout << count;

	return 0;
}

// O(n)
/*
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, count = 0;
	int num;
	bool isPrimeNum;

	cin >> n;

	while (n--) {
		isPrimeNum = true;
		cin >> num;
		if (num > 1) {
			for (int i = 2; i < num / 2 + 1; i++) {
				if (num % i == 0) {
					isPrimeNum = false;
					break;
				}
			}
			if (isPrimeNum) count++;
		}
	}
	cout << count;

	return 0;
}
*/