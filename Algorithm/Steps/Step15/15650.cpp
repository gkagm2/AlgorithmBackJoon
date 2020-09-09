// time : 2^n
#include <iostream>
using namespace std;

bool visit[10];
int a[10];

void go(int idx, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 0; i < m; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	if (idx> n) return;
	a[selected] = idx;
	go(idx + 1, selected + 1, n, m);
	a[selected] = 0;
	go(idx + 1, selected, n, m);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	go(1, 0, n, m);

	return 0;
}

// time : n!
/*
#include <iostream>
using namespace std;

bool visit[10];
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
		if (visit[i])
			continue;
		visit[i] = true;
		a[idx] = i;
		dfs(idx + 1, i + 1, n, m);
		visit[i] = false;
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
*/

/*
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;
bool visit[9];

void DFS(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < vec.size(); ++i) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}
		
	for (int i = 1; i <= n; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			vec.push_back(i);
			DFS(cnt + 1);
			vec.pop_back();

			for (int j = i + 1; j <= n; ++j) {
				visit[j] = false;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	DFS(0);

	return 0;
}
*/