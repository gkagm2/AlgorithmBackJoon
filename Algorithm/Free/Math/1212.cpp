#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string eight[] = { "000", "001","010","011","100","101","110","111" };

	string s ="";
	cin >> s;

	int length = s.length();

	if (length == 1 && s[0] - '0' == 0)
		cout << "0";

	for (int i = 0; i < length; ++i) {
		int n = s[i] - '0';

		if (n < 4 && i == 0) {
			if (n == 0)
				continue;
			else if (n == 1)
				cout << "1";
			else if (n == 2)
				cout << "10";
			else if (n == 3)
				cout << "11";
		}
		else {
			cout << eight[n];
		}
	}
	return 0;
}