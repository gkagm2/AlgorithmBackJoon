#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
vector<int> a;
vector<bool> visit;

void dfs(int idx, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < a.size(); ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (visit[i])
			continue;
		a.push_back(v[i]);
		visit[i] = true;
		dfs(idx + 1, n, m);
		a.pop_back();
		visit[i] = false;
	}
}


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int in;
		cin >> in;
		v.push_back(in);
		visit.push_back(false);
	}
	sort(v.begin(), v.end());
	dfs(0, n, m);

	return 0;
}