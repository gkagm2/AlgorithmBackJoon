#include <iostream>
using namespace std;

// �迭���� �ص� ��.
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count;
	int min = 1000000;
	int max = -1000000;
	int value;

	cin >> count;

	while (count--) {
		cin >> value;
		if (value > max)
			max = value;
		if (value < min)
			min = value;
	}

	cout << min << " " << max;

	return 0;
}