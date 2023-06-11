#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	
	bool isPalindrome = true;
	for (int i = 0; i < str.size() / 2; ++i) {
		char fir;
		char sec;
		fir = str[i];
		sec = str[str.size() - i - 1];
		if (fir != sec) {
			isPalindrome = false;
			break;
		}
	}

	if (isPalindrome)
		cout << 1;
	else
		cout << 0;
	return 0;
}