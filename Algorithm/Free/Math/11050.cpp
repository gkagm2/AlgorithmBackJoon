// DP ¾È½áµµ µÊ
#include <iostream>
using namespace std;

int GetFactorial(int n) {
	int num = 1;
	for (int i = 2; i <= n; ++i) {
		num *= i;
	}
	return num;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	cout << GetFactorial(n) / (GetFactorial(n - k) * GetFactorial(k));

	return 0;
}