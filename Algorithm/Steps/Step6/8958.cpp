#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count;
	char buffer[80];

	int score;
	int totalScore;

	cin >> count;
	cin.ignore(1024, '\n');

	for (int i = 0; i < count; ++i) {
		cin.getline(buffer, 80);

		score = 1;
		totalScore = 0;

		for (int n = 0; n < 80; ++n) {
			if (buffer[n] == '\0') {
				break;
			}
			if (buffer[n] == 'O') {
				totalScore += score;
				++score;
			}
			else if (buffer[n] == 'X') {
				score = 1;
			}
		}
		cout << totalScore << '\n';
	}

	return 0;
}