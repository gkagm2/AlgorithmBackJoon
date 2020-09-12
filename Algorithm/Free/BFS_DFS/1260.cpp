#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> a[1001];
bool visit[1001];
vector<int> e; // edge

queue<int >que;
int n, m, start;

// recursive
void dfs(int c) {
	visit[c] = true;
	cout << c << " ";

	for (int i = 0; i < a[c].size(); ++i) {
		int nextIdx = a[c][i];
		if (!visit[nextIdx])
			dfs(nextIdx);
	}
}

// non recursive
void dfs1(int c) {
	stack<pair<int, int>> stk;
	stk.push(make_pair(c, 0));
	visit[c] = true;
	cout << c << " ";

	while (!stk.empty()) {
		int node = stk.top().first; // ���� ���
		int start = stk.top().second; // ������ index ��ȣ
		stk.pop();
		 
		for (int i = start; i < a[node].size(); ++i) { // ����Ǿ��ִ� ��带 �� ��ȸ
			int next = a[node][i]; // �������� �� ��� ��ȣ�� next�� ��´�.
			if (!visit[next]) { // �湮���� ���� ����
				cout << next << " ";
				visit[next] = true; // �湮�ߴٰ� ǥ���Ѵ���.
				stk.push(make_pair(node, i + 1));
				stk.push(make_pair(next, 0));
				break;
			}
		}
	}
}

void bfs(int start) {
	queue<int> que;
	visit[start] = true;
	que.push(start);

	while (!que.empty()) {
		int node = que.front();
		cout << node << " ";
		que.pop();
		for (int i = 0; i < a[node].size(); ++i) {
			int next = a[node][i];
			if (!visit[next]) {                      
				visit[next] = true;
				que.push(next);
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> start;	

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i < n; ++i) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(start);
	cout << "\n";
	memset(visit, false, sizeof(visit));
	bfs(start);

	return 0;
}