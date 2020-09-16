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