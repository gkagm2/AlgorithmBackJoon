#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int p1Score, p2Score;
	p1Score = p2Score = 100;

	while (n--) {
		int p1, p2;
		cin >> p1 >> p2;

		if (p1 > p2)
			p2Score -= p1;
		else if (p1 < p2)
			p1Score -= p2;

	}
	cout << p1Score << "\n" << p2Score;

	return 0;
}