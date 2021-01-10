#include <iostream>
#include <string>
using namespace std;
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	string input;
	int sum = 0;

	bool alphaCheck[26] = { false, };

	cin >> n;
	while (n--) {
		sum = 0;
		cin >> input;

		for (int i = 0; i < input.size(); ++i) {
			if (input[i] >= 'A' && input[i] <= 'Z') {
				alphaCheck[input[i] -'A'] = true;
				
			}
		}

		for (int i = 0; i < 26; ++i) {
			if (alphaCheck[i] == false)
				sum += i + 'A';
			alphaCheck[i] = false;
		}
		cout << sum << "\n";
	}

	return 0;
}