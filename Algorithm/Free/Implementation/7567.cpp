#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string b;
	
	bool bFlip = true;
	int cm = 0;
	char before = '0';

	cin >> b;
	for (int i = 0; i < b.size(); ++i) {

		if (b[i] != before)
			bFlip = true;
		else
			bFlip = false;

		if (bFlip)
			cm += 10;
		else
			cm += 5;
		before = b[i];
	}
	cout << cm;

	return 0;
}