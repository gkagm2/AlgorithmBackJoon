#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
	ll c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	ll a, b;

	cin >> a >> b;
	ll ans = gcd(a, b);
	for (int i = 0; i < ans; ++i) {
		cout << "1";
	}

	return 0;
}