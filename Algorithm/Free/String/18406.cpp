#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string n;

	cin >> n;

	int leftSum = 0;
	int middle = n.size() / 2;
	for (int i = 0; i <= middle - 1; ++i) {
		leftSum += n[i] - '0';
	}

	int rightSum = 0;
	for (int i = middle; i < n.size(); ++i) {
		rightSum += n[i] - '0';
	}

	cout << (leftSum == rightSum ? "LUCKY" : "READY");

	return 0;
}