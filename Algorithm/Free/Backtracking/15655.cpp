#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;
vector<int> v;
vector<bool> visit;

void dfs(int idx, int start, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < a.size(); ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < n; ++i) {
		if (visit[i]) 
			continue;
		visit[i] = true;
		a.push_back(v[i]);
		dfs(idx + 1, i + 1, n, m);
		a.pop_back();
		visit[i] = false;
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		visit.push_back(false);
	}
	sort(v.begin(), v.end());

	dfs(0, 0, n, m);
	return 0;
}