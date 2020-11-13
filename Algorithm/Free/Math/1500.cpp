#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	ll s, k;
	vector<ll> v;
	ll result = 1;
	cin >> s >> k;

	ll q = s / k;
	ll r = s % k;

	for (int i = 0; i < k; ++i) {
		v.push_back(q);
	}

	for (int i = 0; i < r; ++i) {
		v[i] += 1;
	}
	for (int i = 0; i < k; ++i) {
		result *= v[i];
	}

	cout << result;
	return 0;
}
