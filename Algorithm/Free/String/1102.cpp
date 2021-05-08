#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	int aSize = a.size();
	int bSize = b.size();

	int gap = bSize - aSize;

	int maxSameCnt = 0;
	for (int i = 0; i <= gap; ++i) {
		int cnt = 0;
		for (int j = 0; j < aSize; ++j) {
			if (a[j] == b[i + j])
				++cnt;
		}
		if (cnt > maxSameCnt)
			maxSameCnt = cnt;
	}

	cout << bSize - maxSameCnt - gap;

	return 0;
}