#include <iostream>
#include <cstring>
using namespace std;

bool alphabet[26] = { 0, };

inline void InitAlphabet(bool alphabet[]) {
	for (int i = 0; i < 26; ++i) {
		alphabet[i] = false;
	}
}

inline bool Check(char str[]) {
	for (int j = 0; j < strlen(str); ++j) {
		if (alphabet[str[j] - 'a']) { // 이미 있으면
			return false;
		}
		else { // 없으면	
			alphabet[str[j] - 'a'] = true;
			char temp = str[j];
			while (true) {
				// 알파벳 그룹의 끝까지 간다.
				if (temp != str[j + 1]) {
					break;
				}
				++j;
			}
		}
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	char str[101];
	int groupCount = 0;
	cin >> n;
	cin.ignore(1024, '\n');
	for (int i = 0; i < n; ++i) {
		cin.getline(str, 101);
		InitAlphabet(alphabet);
		if (Check(str)) {
			++groupCount;
		}
	}
	cout << groupCount;

	return 0;
}