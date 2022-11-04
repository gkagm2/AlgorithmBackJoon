#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	int an, bm;

	vector<int> aar;
	vector<int> bar;

	int cnt;

	while (t--) {
		cnt = 0;

		cin >> an >> bm;
		aar.resize(an);
		bar.resize(bm);


		for (int i = 0; i < an; ++i) {
			int val;
			cin >> val;
			aar[i] = val;
		}

		for (int i = 0; i < bm; ++i) {
			int val;
			cin >> val;
			bar[i] = val;
		}

		sort(aar.rbegin(), aar.rend());
		sort(bar.begin(), bar.end());

		for (int i = 0; i < an; ++i) {
			for (int j = 0; j < bm; ++j) {
				if (aar[i] > bar[j])
					++cnt;
				else
					break;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}