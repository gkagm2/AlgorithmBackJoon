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