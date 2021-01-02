// Unsolved

#include <iostream>
#include <set>
using namespace std;
int students[301];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	set<int> s;

	while (n--) {
		int k;
		cin >> k;

		for (int i = 0; i < k; ++i) {
			cin >> students[i];
		}

		int mMax = students[0];
		for (int i = 1; i < k; ++i) {
			if (mMax < students[i])
				mMax = students[i];
		}

		bool isIndependent = true;
		for (int m = 1; m <= mMax; ++m) {
			isIndependent = true;
			for (int i = 0; i < k; ++i) {
				int e = students[i] % m;
				if (s.find(e) != s.end()) {
					isIndependent = false;
					break;
				}
				s.insert(e);
			}
			if (isIndependent) {
				cout << m << "\n";
				break;
			}
			s.clear();
		}
	}
	
	return 0;
}