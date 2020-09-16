#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> a[1001];
bool visit[1001];

void dfs(int vtx) {
	stack<int> stk;
	stk.push(vtx);
	visit[vtx] = true;

	while (!stk.empty()) {
		int curVtx = stk.top();
		stk.pop();
		for (int i = 0; i < a[curVtx].size(); ++i) {
			int nextVtx = a[curVtx][i];
			if (visit[nextVtx] == false) {
				visit[nextVtx] = true;
				stk.push(nextVtx);
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m; // n 정점 , m  간선
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int connectedComponent = 0;

	for (int i = 1; i <= n; ++i) {
		if (visit[i] == false) {
			dfs(i);
			++connectedComponent;
		}
	}

	cout << connectedComponent;
	return 0;
}

/*
// BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[1001];
bool visit[1001];

void bfs(int vtx) {
	queue<int> que;
	visit[vtx] = true;
	que.push(vtx);

	while (!que.empty()) {
		int curVtx = que.front();
		que.pop();
		for (int i = 0; i < a[curVtx].size(); ++i) {
			int nextVtx = a[curVtx][i];
			if (visit[nextVtx] == false) {
				visit[nextVtx] = true;
				que.push(nextVtx);
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m; // n 정점 , m  간선
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int connectedComponent = 0;

	for (int i = 1; i <= n; ++i) {
		if (visit[i] == false) {
			bfs(i);
			++connectedComponent;
		}
	}

	cout << connectedComponent;
	return 0;
}
*/

// DFS
/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> a[1001];
bool visit[1001];

void dfs(int vtx) {
	visit[vtx] = true;
	for (int i = 0; i < a[vtx].size(); ++i) {
		int nextVtx = a[vtx][i];
		if (visit[nextVtx] == false)
			dfs(nextVtx);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m; // n 정점 , m  간선
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int connectedComponent = 0;

	for (int i = 1; i <= n; ++i) {
		if (visit[i] == false) {
			dfs(i);
			++connectedComponent;
		}
	}

	cout << connectedComponent;
	return 0;
}
*/