#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	if (m <= n && m >= 1 && m <= 2)
		cout << "NEWBIE!";
	else if (m <= n)
		cout << "OLDBIE!";
	else
		cout << "TLE!";

	return 0;
}
