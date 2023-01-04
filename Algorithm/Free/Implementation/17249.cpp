#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int leftIdx = str.find('(');
	int rightIdx = str.find(')');

	int leftCnt = 0;
	for (int i = 0; i < leftIdx; ++i) {
		if (str[i] == '@')
			++leftCnt;
	}

	int rightCnt= 0;
	for (int i = rightIdx+ 1; i < str.size(); ++i) {
		if (str[i] == '@')
			++rightCnt;
	}

	cout << leftCnt << " " << rightCnt;

	return 0;
}