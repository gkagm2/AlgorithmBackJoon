#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int alphabet[26] = { 0, };

	char str[1000000];
	cin.getline(str, 1000000);

	// �ҹ��ڷ� �ٲ۴�.
	int i = 0;
	while (str[i]) {
		str[i] = tolower(str[i]);
		++i;
	}

	// ������ ���̸� ���Ѵ�.
	int length = 0;
	while (str[length]) {
		++length;
	}

	// �� ������ ������ ����.
	for (int i = 0; i < length; ++i) {
		++alphabet[(int)str[i] - 'a'];
	}

	// ���� ū ������ �ε����� ���Ѵ�.
	int maxIdx = 0;
	for (int i = 1; i < 26; ++i) {
		if (alphabet[maxIdx] < alphabet[i]) {
			maxIdx = i;
		}
	}

	// ���� ū ���ڰ� �ٸ� ������ ���ڿ� ������ �˻��Ѵ�.
	bool isOnlyOne = true;
	for (int i = 0; i < 26; ++i) {
		if (alphabet[maxIdx] == alphabet[i] && maxIdx != i) {
			isOnlyOne = false;
			break;
		}
	}

	// ���
	if (isOnlyOne) {
		cout << (char)toupper((maxIdx + 'a'));
	}
	else {
		cout << '?';
	}

	return 0;
}