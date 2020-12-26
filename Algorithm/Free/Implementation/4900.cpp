#include <iostream>
#include <string>
#include <map>
using namespace std;
#define ll long long

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
		ll plusIdx = 0;
		ll sz =  input.size() - 1;
		for (ll i = 0; i < sz; ++i) {
			if (input[i] == '+') {
				plusIdx = i;
				break;
			}
		}

		// get code
		string leftCode = "";
		string rightCode = "";
		//left
		for (ll i = 0; i < plusIdx - 1; i += 3)
			leftCode += m[input.substr(i, 3)];

		//right
		for (ll i = plusIdx + 1; i < sz; i += 3)
			rightCode += m[input.substr(i, 3)];

		// get result
		ll result = stoll(leftCode) + stoll(rightCode);

		// print
		cout << input;
		string resultCode = to_string(result);
		for (ll i = 0; i < resultCode.size(); ++i)
			cout << rm[resultCode[i]];
		cout << "\n";
	}

	return 0;
}