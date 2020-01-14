#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tone[8];
	int ascTypeArr[] = { 1,2,3,4,5,6,7,8 };
	int checkCountAsc = 0;
	int checkCountDes = 0;
	
	for (int i = 0; i < 8; ++i) {
		cin >> tone[i]; // ют╥б

		if (tone[i] == ascTypeArr[i]) {
			++checkCountAsc;
		}
		if (tone[i] == ascTypeArr[7 - i]) {
			++checkCountDes;
		}
	}

	if (checkCountAsc == 8) {
		cout << "ascending";
	}
	else if (checkCountDes == 8) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}
	
	return 0;
}