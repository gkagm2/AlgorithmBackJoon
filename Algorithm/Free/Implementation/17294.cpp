#include <iostream>
#include <string>
using namespace std;

int CharToInt(char c) {
	return c - '0';
}

bool IsArithmeticProgression(const string& _input) {
	int commonDifferenceValue;
	int size = _input.size();
	if (size <= 2)
		return true;

	commonDifferenceValue = CharToInt(_input[1]) - CharToInt(_input[0]);
	for (int i = 2; i < size; ++i) {
		int curCommonDifferenceValue = CharToInt(_input[i]) - CharToInt(_input[i - 1]);
		if (commonDifferenceValue != curCommonDifferenceValue)
			return false;
	}
	return true;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string input;
	cin >> input;

	bool isCuteNumber = IsArithmeticProgression(input);

	if (isCuteNumber)
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	else
		cout << "흥칫뿡!! <(￣ ﹌ ￣)>";

	return 0;
}