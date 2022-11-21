#include <iostream>
#include <math.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		double cost;
		cin >> cost;
		cout << fixed;
		cout.precision(2);
		cout << "$" << cost * 0.8 << endl;
	}

	return 0;
}