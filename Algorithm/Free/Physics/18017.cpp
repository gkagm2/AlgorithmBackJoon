#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	double n, m;
	double c = 299792458; //빛
	cin >> n >> m;
	double result = (n + m) / (1 + (n * m) / (c*c));
	cout << fixed;
	cout.precision(10);
	cout << result; // 상대성이론
	return 0;
}