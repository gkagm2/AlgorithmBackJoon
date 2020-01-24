#include <iostream>
#define PI (3.14159265358979323846)
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	double radius;
	cin >> radius;

	cout << fixed;
	cout.precision(6);

	// Euclidean
	cout << PI * radius * radius << '\n';
	// Taxi
	cout << radius * radius * 2.0;

	return 0;
}