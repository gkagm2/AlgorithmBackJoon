#include <iostream>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int data;
	Node(const int &_data) : data(_data), left(nullptr), right(nullptr) {}
	void SetLeft(Node * newleftNode) {
		left = newleftNode;
	}
	void SetRight(Node * newrightNode) {
		right = newrightNode;
	}
};

Node* Insert(Node* root, Node* node) {
	if (root == nullptr) return node;

	if (node->data < root->data )
		root->SetLeft(Insert(root->left, node));
	else
		root->SetRight(Insert(root->right, node));

	return root;
}

void PrintPostorder(Node *node) {
	if(node->left != nullptr)
	PrintPostorder(node->left);
	if (node->right != nullptr)
		PrintPostorder(node->right);
	cout << node->data << "\n";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int data;
	Node *rootNode= nullptr;
	while (cin >> data) {
		rootNode = Insert(rootNode, new Node(data));
	}

	PrintPostorder(rootNode);

	return 0;
}