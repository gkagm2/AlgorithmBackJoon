#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26
#define WORD_SIZE 100

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int alphabetCount[ALPHABET_SIZE];

	char word[WORD_SIZE] = {};


	// 알파벳 배열 초기화
	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		alphabetCount[i] = -1;
	}

	// 입력받고
	cin.getline(word, WORD_SIZE);

	// 입력받은 글자가 몇글자인지 센다.
	int length = 0;
	while (true) {
		if (word[length] == '\0' || word[length] == '\n')
			break;
		++length;
	}
	
	for (int i = 0; i < length; ++i) {
		if (alphabetCount[word[i] - 'a'] == -1) {
			alphabetCount[word[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		cout << alphabetCount[i] << " ";
	}
	return 0;
}