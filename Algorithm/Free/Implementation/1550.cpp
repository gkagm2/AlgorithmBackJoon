#include <iostream>
#include <string>
using namespace std;

inline int OToD(char c) {
	int i;
	switch (c) {
		case 'A':
			i = 10;
		break;
		case 'B':
			i = 11;
			break;
		case 'C':
			i = 12;
			break;

		case 'D':
			i = 13;
			break;
		case 'E':
			i = 14;
			break;
		case 'F':
			i = 15;
			break;
		default:
			i = c - '0';
			break;
	}
	return i;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int answer = 0;

	int zisu = 1;
	for (int i = str.size() - 1; i >= 0; --i) {
		int n = OToD(str[i]);
		answer += n * zisu;
		zisu *= 16;
	}

	cout << answer;

	return 0;
}