#include <iostream>
using namespace std;

struct Node {
	int left;
	int right;
};
Node nodes[27];

void preorder(int i) {
	if (i == -1) return;
	cout << (char)(i + 'A');
	preorder(nodes[i].left);
	preorder(nodes[i].right);
}

void inorder(int i) {
	if (i == -1) return;
	inorder(nodes[i].left);
	cout << (char)(i + 'A');
	inorder(nodes[i].right);
}

void postorder(int i) {
	if (i == -1) return;
	postorder(nodes[i].left);
	postorder(nodes[i].right);
	cout << (char)(i + 'A');
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		char nd, l, r;
		cin >> nd >> l >> r;

		int idx = nd - 'A';

		if (l == '.')
			nodes[idx].left = -1;
		else
			nodes[idx].left = l - 'A';

		if (r == '.')
			nodes[idx].right = -1;
		else
			nodes[idx].right = r - 'A';
	}

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);

	return 0;
}