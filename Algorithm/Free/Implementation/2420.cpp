#include <iostream>
using namespace std;

inline long long abs(long long a, long long b) {
	return a > b ? a - b : b - a;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	long long a, b;
	cin >> a >> b;
	cout << abs(a, b);

	return 0;
}