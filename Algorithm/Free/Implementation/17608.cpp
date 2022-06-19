#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	vector<int> stick;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		stick.push_back(input);
	}

	int lowestHeight = 0;
	int curHeight = 0;
	int result = 0;
	for (int i = 0; i < stick.size(); ++i) {
		int idx = stick.size() - i - 1;

		curHeight = stick[idx];
		if (curHeight > lowestHeight) {
			lowestHeight = curHeight;
			++result;
		}
	}

	cout << result;

	return 0;
}