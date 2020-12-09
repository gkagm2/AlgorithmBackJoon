// used Topology sort
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> questions[32001];
int inDegree[100001];
vector<int> result;
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n, m; // n : 문제의 수 , m : 문제에 대한 정보의 개수
	cin >> n >> m;

	int questionNum, degreeNum;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= m; ++i) {
		cin >> questionNum >> degreeNum;
		questions[questionNum].push_back(degreeNum);
		++inDegree[degreeNum];
	}

	// inDegree가 없는 node를 찾는다.
	for (int i = 1; i <= n; ++i) {
		// 없는 노드는 queue에 넣어준다.
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int x = q.top();
		q.pop();

		result.push_back(x); // 큐에서 꺼낸 순서가 위상정렬의 순서

		// 꺼낸 노드에 연결되어있는 모든 정점들을 확인하여 y node에 연결되어있는 간선을 지움.
		for (int j = 0; j < questions[x].size(); ++j) {
			int y = questions[x][j];
			if (--inDegree[y] == 0) // 연결되어있는 간선을 지웠으면
				q.push(y);
		}
	}

	for (auto v : result)
		cout << v << " ";

	return 0;
}