#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<int> referee;
	int testcase;
	string strResult;
	cin >> testcase;
	while (testcase--) {
		referee.clear();
		for (int i = 0; i < 5; ++i) {
			int score;
			cin >> score;
			referee.push_back(score);
		}
		sort(referee.begin(), referee.end());

		int minScore = referee[1];
		int maxScore = referee[3];
		if (maxScore - minScore >= 4)
			strResult = "KIN";
		else {
			int score = referee[1] + referee[2] + referee[3];
			strResult = to_string(score);
		}

		cout << strResult << "\n";
	}

	return 0;
}