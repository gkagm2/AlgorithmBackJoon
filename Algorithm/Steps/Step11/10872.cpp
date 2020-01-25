#include <iostream>
using namespace std;

inline int Factorial(int num) {
	if (num < 2) {
		return 1;
	}
	return Factorial(num - 1) * num;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	cout << Factorial(num) << endl;
	return 0;
}