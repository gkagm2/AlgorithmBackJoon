#include <iostream>
#include <vector>
using namespace std;

vector<int> in; // inorider
vector<int> post; // postorder

struct Node{
	int data;
	Node* pLeft;
	Node* pRight;
	Node() : data(-1), pLeft(nullptr), pRight(nullptr) {}
};
Node* pRoot = nullptr;

enum class Type {
	root,
	left,
	right
};

void DeleteAll(Node* pParent) {
	if (nullptr == pParent) return;
	DeleteAll(pParent->pLeft);
	DeleteAll(pParent->pRight);
	delete pParent;
}

void PreOrder(Node* pParent) {
	if (nullptr == pParent) return;
	cout << pParent->data << " ";
	PreOrder(pParent->pLeft);
	PreOrder(pParent->pRight);
}

void MakeTree(int inStartIdx, int inEndIdx, int postStartIdx, int postEndIdx, Type eType, Node* pParent) {
	if (inStartIdx > inEndIdx) return;
	if (postStartIdx > postEndIdx) return;

	Node* pNode = new Node();
	pNode->data = post[postEndIdx];

	switch (eType) {
	case Type::root:
		pRoot = pNode;
		break;
	case Type::left:
		pParent->pLeft = pNode;
		break;
	case Type::right:
		pParent->pRight = pNode;
		break;
	}

	if (inStartIdx >= inEndIdx)
		return;

	int inorderParentIdx;
	for (int i = inStartIdx; i <= inEndIdx; ++i) {
		if (in[i] == pNode->data) {
			inorderParentIdx = i;
			break;
		}
	}

	MakeTree(inStartIdx, inorderParentIdx - 1, postStartIdx, postStartIdx + (inorderParentIdx - inStartIdx - 1), Type::left, pNode);
	MakeTree(inorderParentIdx + 1, inEndIdx, postEndIdx - (inEndIdx - inorderParentIdx), postEndIdx - 1, Type::right, pNode);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		in.push_back(t);
	}

	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		post.push_back(t);
	}

	MakeTree(0, n - 1, 0, n - 1, Type::root, nullptr);
	PreOrder(pRoot);

	DeleteAll(pRoot);
	return 0;
}