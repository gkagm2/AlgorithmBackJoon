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