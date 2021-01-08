#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a[3];
	while (true) {
		cin >> a[0] >> a[1] >> a[2];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0)
			break;
		
		sort(a, a + 3);
		if (a[0] + a[1] <= a[2]) {
			cout << "Invalid\n";
			continue;
		}

		if(a[0] == a[1] && a[1] == a[2])
			cout << "Equilateral\n";
		else if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2])
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}

	return 0;
}