#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char str[101];
	cin >> str;

	int length = 0;
	while (str[length] != '\0') {
		++length;
	}
	cout << length;

	return 0;
}