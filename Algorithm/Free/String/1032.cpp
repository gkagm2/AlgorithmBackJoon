#include <iostream>
using namespace std;

int GetLength(char str[]) {
	int cnt = 0;
	
	while (str[cnt] != '\0') {
		++cnt;
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	char fileName[51];
	char fName[51];
	cin >> fileName;
	cin.ignore(1024, '\n');
	int length = GetLength(fileName);

	if (n > 1) {
		--n;
		while (n--) {
			cin >> fName;

			for (int i = 0; i < length; ++i) {
				if (fileName[i] != fName[i]) {
					fileName[i] = '?';
				}
			}
		}
	}
	
	cout << fileName;

	return 0;
}