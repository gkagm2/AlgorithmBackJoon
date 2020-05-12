#include <iostream>
#include <string>
using namespace std;

string ar[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string n;
	cin >> n;

	for (int i = 0; n.size() % 3; ++i) {
		n = "0" + n;
	}
	for (int i = 0; i <= n.size() - 3; i+=3) {
		string str = n.substr(i, 3);
		for (int i = 0; i < 8; ++i) {
			if (str == ar[i]) {
				cout << i;
				break;
			}
		}
	}
	return 0;
}
