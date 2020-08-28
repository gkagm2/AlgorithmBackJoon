#include <iostream>
using namespace std;

int arr[11];

// Botttom top
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	arr[0] = 1;

	for (int i = 1; i <= 10; ++i) {
		if (i - 1 >= 0)
			arr[i] += arr[i - 1];
		if (i - 2 >= 0)
			arr[i] += arr[i - 2];
		if (i - 3 >= 0)
			arr[i] += arr[i - 3];
	}

	int cnt, n;
	cin >> cnt;
	while (cnt--) {
		cin >> n;
		cout << arr[n] << "\n";
	}
	
	return 0;
}