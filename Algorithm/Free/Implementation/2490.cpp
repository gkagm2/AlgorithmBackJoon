#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int y[4];

	char alpha[6] = { 'A','B','C','D','E', };
	int arr[5][2] = { { 1,3 },{ 2,2, },{ 3,1 },{ 4, 0 },{ 0,4 } };

	for (int i = 0; i < 3; ++i) {
		int b = 0; // 0
		int d = 0; // 1
		int input;
		for (int j = 0; j < 4; ++j) {
			cin >> input;
			if (input == 0)
				++b;
			else
				++d;
		}

		// check
		for (int j = 0; j < 5; ++j) {
			if (arr[j][0] == b && arr[j][1] == d) {
				cout << alpha[j] << "\n";
				break;
			}
		}
	}


	return 0;
}