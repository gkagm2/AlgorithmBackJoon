#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string strResult;
	int result = 0;
	for (int i = n; i >= 4; --i) {
		string strNum = to_string(i);
		bool pass = true;

		for (int j = 0; j < strNum.size(); j++) {
			int num = strNum[j] - '0';
			if (num == 4)
				continue;
			else if (num == 7)
				continue;
			else {
				pass = false;
				break;
			}
		}

		if (pass) {
			result = i;
			break;
		}
	}

	cout << result;

	return 0;
}