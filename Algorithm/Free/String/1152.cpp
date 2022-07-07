#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str;

	getline(cin, str);

	bool wordStart = false;
	bool wordEnd = false;
	int wordCnt = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ' ') {
			if (true == wordStart) {
				wordStart = false;
				++wordCnt;
			}
		}
		else {
			if (wordStart == false)
				wordStart = true;
		}
	}
	if (wordStart)
		++wordCnt;

	cout << wordCnt;

	return 0;
}