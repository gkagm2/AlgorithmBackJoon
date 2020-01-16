#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char str[1000000] = {};
	cin.getline(str, 1000000);

	int idx = 0;
	char state = 0;
	int wordCount = 0;

	while (str[idx]) {
		if (str[idx] == ' ') {
			if (state != 0) {
				state = 0;
			}
		}
		if (str[idx] > 33 && state == 0) {
			++wordCount;
			state = 1;
		}
		++idx;
	}

	cout << wordCount;

	return 0;
}