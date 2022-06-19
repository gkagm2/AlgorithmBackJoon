#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string strText = "";
	string strDecodingText = "";
	getline(cin, strText);

	int i = 0;
	while (i < strText.size()) {
		if (i + 1 < strText.size() - 1) {
			if ('p' != strText[i + 1]) {
				strDecodingText += strText[i];
				++i;
			}
			else {
				int j = i + 1;
				if (j >= 1 && j <= strText.size() - 2) {
					bool isSame = false;
					if (strText[j - 1] == strText[j + 1]) {
						if('a' == strText[j - 1] ||
							'e' == strText[j - 1] ||
							'i' == strText[j - 1] ||
							'o' == strText[j-1] ||
							'u' == strText[j-1])
							isSame = true;
					}
						
					if (isSame) {
						strDecodingText += strText[j - 1];
						j += 2;
						i = j;
					}
					else {
						strDecodingText += strText[i];
						++i;
					}
				}
			}
		}
		else {
			strDecodingText += strText[i];
			++i;
		}
	}

	cout << strDecodingText;
	
	return 0;
}
