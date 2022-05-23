#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	set<string> se;

	int n;
	string str;

	cin >> n;
	
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if ("ENTER" == s) {
			cnt += se.size();
			se.clear();
		}
		else
			se.insert(s);
	}
	cnt += se.size();
	cout << cnt;

	return 0;
}