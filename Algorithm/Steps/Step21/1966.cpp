#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		queue<pair<int, int>> que;
		priority_queue<int> pque;

		int printCnt, findNum;
		cin >> printCnt >> findNum;

		for (int num = 0; num < printCnt; ++num) {
			int priority;
			cin >> priority;
			que.push(make_pair(num, priority));
			pque.push(priority);
		}

		int cnt = 0;
		while (!pque.empty()) {
			++cnt;
			int priority = pque.top();

			int printNum = que.front().first;
			int printPriority = que.front().second;

			while (priority != printPriority) {
				que.pop();
				que.push(make_pair(printNum, printPriority));
				printNum = que.front().first;
				printPriority = que.front().second;
			}

			if (printNum == findNum && priority == printPriority) {
				break;
			}
			que.pop();
			pque.pop();
		}

		cout << cnt << "\n";
	}

	return 0;
}