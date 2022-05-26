#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string strInput;
	cin >> strInput;

	int firNum;
	int secNum;
	bool isDone = false;

	for (int i = 1; i <= 999; ++i) {
		string strNum;
		firNum = i;
		for (int j = i; j <= 999; ++j) {
			secNum = j;
			strNum += to_string(j);

			if (strNum == strInput) {
				isDone = true;
				break;
			}
			if (strInput.size() < strNum.size())
				break;
		}
		if (isDone)
			break;
	}

	cout << firNum << " " << secNum;

	return 0;
}