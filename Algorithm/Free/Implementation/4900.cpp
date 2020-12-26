#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	char cNum[] = { '0','1','2','3','4','5','6','7','8','9' };
	string code[] = {
		"063", "010", "093", "079", "106", "103", "118", "011", "127", "107" };

	map<string, char> m;
	map<char, string> rm;
	for (int i = 0; i <= 9; ++i) {
		m.insert(make_pair(code[i], cNum[i]));
		rm.insert(make_pair(cNum[i], code[i]));
	}

	string input;
	while (cin >> input) {
		if (input == "BYE")
			break;

		// find idx
		unsigned int plusIdx = 0;
		for (unsigned int i = 0; i < input.size(); ++i) {
			if (input[plusIdx] == '+') {
				plusIdx = i;
				break;
			}
		}

		// get code
		string leftCode = "";
		string rightCode = "";
		//left
		for (unsigned int i = 0; i < plusIdx - 1; i += 3)
			leftCode += m[input.substr(i, 3)];

		//right
		for (unsigned int i = plusIdx + 1; i < input.size() - 2; i += 3)
			rightCode += m[input.substr(i, 3)];

		// get result
		unsigned int result = stoi(leftCode) + stoi(rightCode);

		// print
		cout << input;
		string resultCode = to_string(result);
		for (unsigned int i = 0; i < resultCode.size(); ++i)
			cout << rm[resultCode[i]];
		cout << "\n";
	}

	return 0;
}