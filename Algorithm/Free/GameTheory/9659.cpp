#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	long long n;

	cin >> n;
	if (n % 2)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}