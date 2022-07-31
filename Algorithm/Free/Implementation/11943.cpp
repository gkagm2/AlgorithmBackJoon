#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b, c, d;

	cin >> a >> b;
	cin >> c >> d;

	int res1 = a + d;
	int res2 = b + c;
	cout << min(res1, res2);

	return 0;
}