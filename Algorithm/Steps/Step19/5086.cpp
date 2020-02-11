#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	int mul;

	while (true) {
		cin >> a >> b;
		if (!a && !b) {
			break;
		}
		if (b % a == 0) {
			cout << "factor\n";
		}
		else if (a % b == 0) {
			cout << "multiple\n";
		}
		else {
			cout << "neither\n";
		}
	}

	return 0;
}