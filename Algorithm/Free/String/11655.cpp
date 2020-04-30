#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char a;

	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			a = 'a';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			a = 'A';
		}
		else {
			cout << str[i];
			continue;
		}
		cout << (char)(a + (str[i] - a + 13) % 26);
	}

	return 0;
}