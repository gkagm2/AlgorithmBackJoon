// 위상정렬
// 1. 진입차수가 0인 정점과 이와 연결된 모든 간선을 지운다.
// 2. 남아있는 정점의 진입차수를 갱신한다.
// 3. 그래프에 모든 정점이 없어질 때까지 1과 2를 반복한다.  

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[32001];
int indegree[32001] = {};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		++indegree[b];
		v[a].push_back(b);
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (0 == indegree[i]) 
			q.push(i);
	}
	
	while (!q.empty()) {
		int e = q.front();
		q.pop();

		cout << e << " ";

		for (int i = 0; i < v[e].size(); i++) {
			if (0 == --indegree[v[e][i]])
				q.push(v[e][i]);
		}
	}

	return 0;
}