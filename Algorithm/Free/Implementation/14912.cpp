#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;

	int iNum = stoi(s1);
	int d = stoi(s2);
	int cnt = 0;
	for (int i = 1; i <= iNum; ++i) {
		string s = to_string(i);
		for (int j = 0; j < s.size(); ++j) {
			int n = s[j] - '0';
			if (d == n)
				++cnt;
		}
	}

	cout << cnt;

	return 0;
}