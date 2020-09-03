#include <iostream>
using namespace std;

// 최대 공약수
inline int GCD(int a, int b)
{
	if (b == 0) return a;

	long long temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

inline int ABS(int a) {
	return a < 0 ? -a : a;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int *arr = new int[n + 1];

	int s;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i] = ABS(s - arr[i]);
	}
	int min = arr[0];
	if (n > 1) {
		for (int i = 1; i < n; ++i) {

			min = GCD(min, arr[i]);
		}
	}
	cout << min;

	delete[] arr;
	return 0;
}