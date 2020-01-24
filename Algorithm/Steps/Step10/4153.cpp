#include <iostream>
using namespace std;

inline void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num[3];

	while (true) {
		cin >> num[0] >> num[1] >> num[2];
		if (!num[0] && !num[1] && !num[2])
			break;
		
		if (num[0] > num[1])
			swap(num[0],num[1]);
		if (num[1] > num[2])
			swap(num[1], num[2]);
		if (num[0] > num[1])
			swap(num[0], num[1]);

		if (num[0] * num[0] + num[1] * num[1] == num[2] * num[2])
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	return 0;
}