#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;
	if (n % 2)
		cout << "CY";
	else
		cout << "SK";

	return 0;
}