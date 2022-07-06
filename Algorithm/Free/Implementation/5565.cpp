#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int totalCost = 0;
	int curCost;
	cin >> curCost;

	for (int i = 0; i < 9; ++i) {
		int bookCost;
		cin >> bookCost;
		totalCost += bookCost;
	}

	cout << curCost - totalCost;
	
	return 0;
}