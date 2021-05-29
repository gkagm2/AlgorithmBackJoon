// ��������
// 1. ���������� 0�� ������ �̿� ����� ��� ������ �����.
// 2. �����ִ� ������ ���������� �����Ѵ�.
// 3. �׷����� ��� ������ ������ ������ 1�� 2�� �ݺ��Ѵ�.  

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