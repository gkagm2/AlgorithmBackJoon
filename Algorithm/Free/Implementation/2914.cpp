#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << a * (b - 1) + 1;

	return 0;
}