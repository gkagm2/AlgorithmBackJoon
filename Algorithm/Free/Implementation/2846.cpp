#include <iostream>
#include <vector>
using namespace std;
#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	vector<int> heights;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int height;
		cin >> height;
		heights.push_back(height);
	}

	// Check
	int startHeight = 0;
	int acc;
	bool isStartUpHill = false;
	int lastHeight = 0;
	int resultOffset = 0;
	

	for (int i = 0; i < heights.size() - 1; ++i) {
		if (heights[i] < heights[i + 1]) {
			if (isStartUpHill) {
				lastHeight = heights[i + 1];
				int curGap = lastHeight - startHeight;
				if (resultOffset < curGap)
					resultOffset = curGap;
			}
			else {
				isStartUpHill = true;
				startHeight = heights[i];
			}
		}
		else {
			if (isStartUpHill) {
				lastHeight = heights[i];
				int curGap = lastHeight - startHeight;
				if (resultOffset < curGap)
					resultOffset = curGap;
			}
			isStartUpHill = false;
		}
	}

	cout << resultOffset;


	return 0;
}