#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int cnt = 0;
	multimap<int, int> map;
	cin >> cnt;
	vector<bool> visit(cnt + 1, false);
	int path;
	cin >> path;

	for (int i = 0; i < path; i++) {
		int from, to;
		cin >> from >> to;
		map.insert(make_pair(to, from));
		map.insert(make_pair(from, to));
	}
	queue<int> que;
	que.push(1);
	visit[1] = true;
	
	int virusCnt = 0;
	while (!que.empty()) {
		int startNode = que.front();
		que.pop();
		for (auto iter = map.begin(); iter != map.end(); ++iter) {
			if (visit[iter->second])
				continue;
			if (startNode == iter->first) {
				que.push(iter->second);
				++virusCnt;
				visit[iter->second] = true;
			}
		}
	}
	cout << virusCnt;
	return 0;
}