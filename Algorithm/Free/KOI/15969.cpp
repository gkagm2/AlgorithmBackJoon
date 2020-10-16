#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int min, max;

	vector<int> score;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		score.push_back(t);
	}

	min = max = score[0];
	for (int i = 1; i < score.size(); ++i) {
		if (min > score[i])
			min = score[i];
		if (max < score[i])
			max = score[i];
	}

	cout << max - min;

	return 0;
}