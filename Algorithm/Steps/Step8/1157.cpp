#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int alphabet[26] = { 0, };

	char str[1000000];
	cin.getline(str, 1000000);

	// 소문자로 바꾼다.
	int i = 0;
	while (str[i]) {
		str[i] = tolower(str[i]);
		++i;
	}

	// 문자의 길이를 구한다.
	int length = 0;
	while (str[length]) {
		++length;
	}

	// 각 문자의 개수를 센다.
	for (int i = 0; i < length; ++i) {
		++alphabet[(int)str[i] - 'a'];
	}

	// 가장 큰 숫자의 인덱스를 구한다.
	int maxIdx = 0;
	for (int i = 1; i < 26; ++i) {
		if (alphabet[maxIdx] < alphabet[i]) {
			maxIdx = i;
		}
	}

	// 가장 큰 숫자가 다른 문자의 숫자와 같은지 검사한다.
	bool isOnlyOne = true;
	for (int i = 0; i < 26; ++i) {
		if (alphabet[maxIdx] == alphabet[i] && maxIdx != i) {
			isOnlyOne = false;
			break;
		}
	}

	// 출력
	if (isOnlyOne) {
		cout << (char)toupper((maxIdx + 'a'));
	}
	else {
		cout << '?';
	}

	return 0;
}