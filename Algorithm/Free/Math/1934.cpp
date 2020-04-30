#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int mod = a % b;
	while (mod > 0)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	int a, b, g;
	while (cnt--) {
		cin >> a >> b;
		g = gcd(a, b);
		cout << g * (a/ g) * (b/ g) << '\n';
	}

	return 0;
}