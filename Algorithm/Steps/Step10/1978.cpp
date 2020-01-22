#include <iostream>
using namespace std;

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