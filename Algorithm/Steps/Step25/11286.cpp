#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PAIR;

int Abs(int n) {
	return n < 0 ? -1 * n : n;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
	int n;
	cin >> n;

	while (n--) {
		int num;
		cin >> num;

		if (num == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(Abs(num), num));
		}
	}

	return 0;
}