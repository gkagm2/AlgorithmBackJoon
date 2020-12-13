#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int num;
	while (cin >> num) {
		if (num == 0)
			break;
		if (num % n == 0)
			cout << num << " is a multiple of " << n << ".\n";
		else
			cout << num << " is NOT a multiple of " << n << ".\n";
	}
	
	return 0;
}