#include <iostream>
#include <string>
using namespace std;

bool IsVowel(char c) {
	if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c)
		return true;
	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string word;

	while (1) {
		cin >> word;
		if ("end" == word)
			break;

		// check ����
		bool isOk[4] { false, true, true, true };

		for (int i = 0; i < word.size(); ++i) {
			char c = word[i];
			if (IsVowel(c)) {
				isOk[0] = true;
				break;
			}
		}

		// ������ ���ӵǾ����� Ȯ��
		{
			int conCount = false;
			int startIdx = 0;
			bool isStart = false;
			int lastIdx = word.size() - 3;
			for (int i = 0; i <= lastIdx; ++i, startIdx = i) {
				if (!isStart) {
					isStart = true;
					startIdx = i;
				}

				if (isStart) {
					int cnt = 0;
					for (int j = startIdx; j < startIdx + 3; ++j) {
						if (IsVowel(word[j]))
							++cnt;
					}
					// ���ӵǾ�����
					if (3 == cnt) {
						isOk[1] = false;
						break;
					}
				}
			}
		}
		
		// ������ ���ӵǾ����� Ȯ��
		{
			int conCount = false;
			int startIdx = 0;
			bool isStart = false;
			int lastIdx = word.size() - 3;
			for (int i = 0; i <= lastIdx; ++i, startIdx = i) {
				if (!isStart) {
					isStart = true;
					startIdx = i;
				}

				if (isStart) {
					isStart = true;
					bool isAllJaum = true;
					int cnt = 0;
					for (int j = startIdx; j < startIdx + 3; ++j) {
						if (!IsVowel(word[j]))
							++cnt;
					}

					// ���ӵǾ�����
					if (3 == cnt) {
						isOk[2] = false;
						break;
					}
				}
			}
		}

		// ���� ���� ���������� ã��
		{
			int lastIdx = word.size() - 2;
			for (int i = 0; i < lastIdx; ++i) {
				if (word.size() >= 2 && word[i] == word[i + 1]) {
					if (word[i] != 'e' && word[i] != 'o') {
						isOk[3] = false;
						break;
					}
				}
			}
		}
	

		if (isOk[0] && isOk[1] && isOk[2] && isOk[3])
			cout << "<" << word << "> is acceptable.\n";
		else
			cout << "<" << word << "> is not acceptable.\n";
	}
	return 0;
}