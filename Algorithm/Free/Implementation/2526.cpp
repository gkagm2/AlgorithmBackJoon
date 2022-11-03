#include <iostream>
#include <unordered_map>
using namespace std;

#define KEY int
#define CALL_COUNT int

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	unordered_map<KEY, CALL_COUNT> m;

	int n, p;
	cin >> n >> p;

	int val = n;
	while (1) {
		m[val]++;
		if (2 < m[val])
			break;
		val = val * n % p;
	}

	auto it = m.begin();
	int cnt = 0;
	while (it != m.end()) {
		if (it->second > 1)
			++cnt;
		++it;
	}
	cout << cnt;

	return 0;
}
