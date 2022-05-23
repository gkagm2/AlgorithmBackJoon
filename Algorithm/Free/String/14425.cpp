#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	set<string> se;

	int s, m;

	cin >> m >> s;
	string str;
	for (int i = 0; i < m; ++i) {
		cin >> str;
		se.insert(str);
	}

	int cnt = 0;
	for (int i = 0; i < s; ++i) {
		string str;
		cin >> str;
		if (se.find(str) != se.end())
			++cnt;
	}

	cout << cnt;

	return 0;
}
