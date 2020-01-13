#include <iostream>
using namespace std;

int main() {
	int a, b;
	
	cin >> a;
	cin >> b;

	cout << fixed;
	cout.precision(15);
	cout << a / (double)b;

	return 0;
}