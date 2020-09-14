#include <iostream>
#include <algorithm>
using namespace std;

int l, c;

char alpha[15];
char password[15];
bool visit[15];

bool check() {
	int mo = 0;
	int ja = 0;
	for (int i = 0; i < l; ++i) {
		char alpha = password[i];
		if (alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u')
			++mo;
		else
			++ja;
	}
	return mo >= 1 && ja >= 2;
}

void dfs(int passwordCnt, int start) {
	if (passwordCnt == l)
	{
		if (check()) {
			for (int i = 0; i < l; ++i) {
				cout << password[i];
			}
			cout << "\n";
		}
		return;
	}

	for (int i = start; i < c; ++i) {
		if (visit[i]) continue;
		visit[i] = true;
		password[passwordCnt] = alpha[i];
		dfs(passwordCnt + 1, i + 1);
		visit[i] = false;
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> l >> c;	
	for (int i = 0; i < c; ++i) {
		cin >> alpha[i];
	}
	sort(alpha, alpha + c);

	dfs(0, 0);
	return 0;
}