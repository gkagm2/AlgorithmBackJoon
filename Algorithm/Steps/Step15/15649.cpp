#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
bool visit[9];

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		v.push_back(i);
		solve(cnt + 1);
		visit[i] = 0;
		v.pop_back();	
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	solve(0);
	return 0;
}