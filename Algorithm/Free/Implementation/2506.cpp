#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	int score = 0;
	int accCnt = 0;



	for (int i = 0; i < n; ++i) {
		int inputScore;
		cin >> inputScore;
		
		if (inputScore)
			++accCnt;
		else
			accCnt = 0;

		score += accCnt;
	}

	cout << score;
	return 0;
}