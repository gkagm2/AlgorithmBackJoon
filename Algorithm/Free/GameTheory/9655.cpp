#include <iostream>
using namespace std;

int dp[1001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	if (n % 2)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}