#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	int a;
	int b, c;
	vector<int> v;
	long long supCnt = 0;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int pn;
		cin >> pn;
		v.push_back(pn);
	}

	cin >> b >> c;

	for (int i = 0; i < v.size(); ++i) {
		v[i] = v[i] - b;
		++supCnt;

		if (v[i] > 0) {
			int subsup;
			subsup = v[i] / c;
			if (v[i] % c > 0)
				subsup++;

			supCnt += subsup;
		}
	}

	cout << supCnt;
	return 0;
}