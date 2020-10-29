#include <iostream>
#include <vector>
using namespace std;

#define max_size 100001

vector<int> tree[max_size];
int parent[max_size];
bool visited[max_size];

void FindParent(int _nodeNum) {
	visited[_nodeNum] = true;

	for (int i = 0; i < tree[_nodeNum].size(); ++i) {
		int nextNode = tree[_nodeNum][i];
		if (!visited[nextNode]) {
			parent[nextNode] = _nodeNum;
			FindParent(nextNode);	
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;
	
	for(int i=0 ;i < n - 1; ++i) {
		int node1, node2;
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	FindParent(1);

	for (int i = 2; i <= n; ++i)
		cout << parent[i] << "\n";

	return 0;
}