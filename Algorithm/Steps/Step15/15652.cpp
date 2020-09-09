#include <iostream>
using namespace std;

int a[10];

void dfs(int idx, int start, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; ++i) {
		a[idx] = i;
		dfs(idx + 1, i,  n, m);
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	dfs(0, 1, n, m);

	return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

int n, m, x;
vector<int > vec;

void DFS(int index, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < vec.size(); ++i) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = index; i <= n; ++i) {
		vec.push_back(i);
		DFS(i, cnt + 1);
		vec.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	DFS(1, 0);
	return 0;
}
*/