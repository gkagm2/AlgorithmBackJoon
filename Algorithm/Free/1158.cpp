#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<int> que;

	int cnt, jumpCnt;

	cin >> cnt >> jumpCnt;

	for (int i = 1; i <= cnt; ++i) {
		que.push(i);
	}

	cout << "<";
	while (que.size() != 1) {
		for (int i = 0; i < jumpCnt; ++i) {
			if (jumpCnt - 1 == i)
			{
				cout << que.front() << ", ";
				que.pop();
				break;
			}
			que.push(que.front());
			que.pop();
		}
	}
	cout << que.front() << ">";

	return 0;
}
