// 나중에 Heap 직접 만들어서 시간 단축해봐야 될 듯
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PAIR;

int Abs(int n) {
	return n < 0 ? -1 * n : n;
}

int main() {

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