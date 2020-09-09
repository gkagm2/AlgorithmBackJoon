#include <iostream>
using namespace std;

int a[10];

void dfs(int idx, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i) {
		a[idx] = i;
		dfs(idx + 1, n, m);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	dfs(0, n, m);
		
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<int> vec;
int visit[9];

void DFS(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < vec.size(); ++i) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (visit[i] == n) {
			continue;
		}

		++visit[i];
		vec.push_back(i);
		DFS(cnt + 1);
		visit[i] = 0;
		vec.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	memset(visit, 0, sizeof(visit));
	DFS(0);

	return 0;
}
*/