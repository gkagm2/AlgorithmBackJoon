#include <iostream>
#include <string.h>
using namespace std;

void Swap(char _cType, int cup[3]) {
	int* a = nullptr;
	int* b = nullptr;
	if (_cType == 'A') {
		a = &cup[0];
		b = &cup[1];
	}
	else if (_cType == 'B') {
		a = &cup[1];
		b = &cup[2];
	}
	else {
		a = &cup[0];
		b = &cup[2];
	}

	int t = *a;
	*a = *b;
	*b = t;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	char c[50];
	cin >> c;
	int cnt = 0;
	cnt = strlen(c);

	int cup[3] = { 1,0,0 };

	for (int i = 0; i < cnt; ++i) {
		Swap(c[i], cup);
	}

	for (int i = 0; i < 3; ++i) {
		if (cup[i] == 1) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}