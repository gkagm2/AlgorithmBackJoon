#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ALPHABET_SIZE 26

bool IsPangram(const string& str, vector<char>& _retNotIncludedWords) {
	bool isPangram = true;
	bool alphaExist[ALPHABET_SIZE] = { 0, };

	for (int i = 0; i < str.size(); ++i) {
		char c = tolower(str[i]);

		if (c >= 'a' && c <= 'z') {
			int idx = c - 97;
			alphaExist[idx] = true;
		}
	}

	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		if (alphaExist[i] == false) {
			isPangram = false;
			break;
		}
	}

	if (isPangram == false) {
		_retNotIncludedWords.resize(0);
		for(int i=0 ;i < ALPHABET_SIZE;++i)
			if (0 == alphaExist[i])
				_retNotIncludedWords.push_back((char)i + 97);
	}

	return isPangram;
}

int main() {
	
	string strCnt;
	cin >> strCnt;
	cin.ignore();
	int cnt = stoi(strCnt);
	while (cnt--) {
		string str = "";
		getline(cin, str);
		vector<char> vecNotIncludedWord;
		if (IsPangram(str, vecNotIncludedWord))
			cout << "pangram\n";
		else {
			cout << "missing ";
			for (int i = 0; i < vecNotIncludedWord.size(); ++i) {
				cout << vecNotIncludedWord[i];
			}
			cout << "\n";
		}
	}

	return 0;
 }