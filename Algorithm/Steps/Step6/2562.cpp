#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int arr[9];
	int idx = 0;
	int i;
	int max;
	cin >> arr[0];
	max = arr[0];
	idx = 0;
	for (i = 1; i < 9; ++i) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
			idx = i;
		}
	}

	cout << max << '\n' << idx + 1;

	return 0;
}