#include <iostream>
#include <cstring>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	char s[100];

	cin >> s;

	int alpha[26];
	for (int i = 0; i < 26; ++i) {
		alpha[i] = -1;
	}

	for (int i = 0; i < strlen(s); ++i) {
		if(alpha[s[i]-'a'] == -1)
			alpha[s[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; ++i) {
		cout << alpha[i] << ' ';
	}

	return 0;
}
