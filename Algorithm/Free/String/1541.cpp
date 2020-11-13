#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	string temp = "";

	int result = 0;
	bool isMinus = false;
	for (int i = 0; i <= str.size(); ++i) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (isMinus) {
				result -= stoi(temp);
			}
			else {
				result += stoi(temp);
			}
			if (str[i] == '-')
				isMinus = true;

			temp = "";
		}
		else {
			temp += str[i];
		}
	}

	cout << result;

	return 0;
}