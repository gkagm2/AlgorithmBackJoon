#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	short alphabetCnt[26];

	for (short i = 0; i < 26; ++i) {
		alphabetCnt[i] = 0;
	}

	string word;
	cin >> word;

	for (short i = 0; i < word.length(); ++i) {
		++alphabetCnt[word[i] - 'a'];
	}

	for (short i = 0; i < 26; ++i) {
		cout << alphabetCnt[i] << ' ';
	}

	return 0;
}
