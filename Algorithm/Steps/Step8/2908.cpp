#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char ac[4];
	char bc[4];

	cin >> ac;
	cin >> bc;

	bool isBBigger; // ac : false, bc : true
	for (int i = 2; i >= 0; --i) {
		if ((int)ac[i] > (int)bc[i]) {
			isBBigger = false;
			break;
		}
		else if ((int)ac[i] < (int)bc[i]) {
			isBBigger = true;
			break;
		}
	}

	int i = 2;
	while (i >= 0) {
		cout << (isBBigger == true ? bc[i] : ac[i]);
		--i;
	}

	return 0;
}