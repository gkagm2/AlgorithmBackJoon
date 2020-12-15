#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree(51);
int n; 
int root;
int childCnt = 0;
int delN;

// DFS
void GetLeapCnt(const int parent) {
	if (parent == delN)
		return;

	if (tree[parent].size() == 0 && parent != delN)
		++childCnt;
	else if (tree[parent].size() == 1 && tree[parent][0] == delN) {
		++childCnt;
	}
	else {
		for (int child = 0; child < tree[parent].size(); ++child) {
			GetLeapCnt(tree[parent][child]);
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	tree.resize(n);

	for (int nNum = 0; nNum < n; ++nNum) {
		int parent;
		cin >> parent;
		if (parent == -1)
			root = nNum;
		else
			tree[parent].push_back(nNum);
	}

	cin >> delN;
	GetLeapCnt(root);

	cout << childCnt;
	return 0;
}