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