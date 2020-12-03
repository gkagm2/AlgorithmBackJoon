#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<vector<int> > vTeam;

	int n, k, l;
	int rating;

	cin >> n >> k >> l;
	for (int i = 0; i < n; ++i) {
		vector<int> vPerson;
		bool personalRatingOk = true;

		int teamSum = 0;
		for (int j = 0; j < 3; ++j) {
			cin >> rating;
			if (rating < l)
				personalRatingOk = false;
			if (personalRatingOk) {
				vPerson.push_back(rating);
				teamSum += rating;
			}
		}
		if (personalRatingOk && teamSum >= k)
			vTeam.push_back(vPerson);
	}

	cout << vTeam.size() << "\n";
	for (int i = 0; i < vTeam.size(); ++i) {
		for (int j = 0; j < vTeam[i].size(); ++j) {
			cout << vTeam[i][j] << " ";
		}
	}

	return 0;
}