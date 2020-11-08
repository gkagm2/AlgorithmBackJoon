#include <iostream>
using namespace std;

void Hanoi(int n, int from, int to, int aus) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}

	Hanoi(n - 1, from, aus, to);
	cout << from << " " << to << "\n";
	Hanoi(n - 1, aus, to, from);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int moveCnt = (1 << n) - 1;
	cout << moveCnt << "\n";
	Hanoi(n, 1, 3, 2);

	return 0;
}