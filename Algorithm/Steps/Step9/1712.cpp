#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int fixedCost, variableCost, productCost;
	cin >> fixedCost >> variableCost >> productCost;

	if (variableCost >= productCost) {
		cout << -1;
	}
	else {
		cout << fixedCost / (productCost - variableCost) + 1;
	}

	return 0;
}