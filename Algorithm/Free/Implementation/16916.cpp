#include <iostream>
#include <string.h>
using namespace std;

char str[1000001];
char str2[1000001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> str >> str2;
	char* ret = strstr(str, str2);
	if (nullptr == ret)
		cout << 0;
	else
		cout << 1;

	return 0;
}