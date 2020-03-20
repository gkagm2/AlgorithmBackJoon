// In Step5
#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int burgerCost[3];
	int drinkCost[2];

	cin >> burgerCost[0];
	cin >> burgerCost[1];
	cin >> burgerCost[2];
	cin >> drinkCost[0];
	cin >> drinkCost[1];

	// get min
	int burgerMin = burgerCost[0];
	for (int i = 1; i <= 2; i++)
	{
		if (burgerCost[i] < burgerMin) {
			burgerMin = burgerCost[i];
		}
	}

	int drinkMin = drinkCost[0] < drinkCost[1] ? drinkCost[0] : drinkCost[1];

	cout << burgerMin + drinkMin - 50;
	return 0;
}
