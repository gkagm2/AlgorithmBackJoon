#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	string com[2] = { "JOI", "IOI" };
	int cnt[2] = { 0,0 };

	if (str.size() >= 3) {
		for (int i = 0; i < str.size() - 2; ++i) {
			string sub = str.substr(i, 3);
			for (int j = 0; j < 2; ++j) {
				if (com[j] == sub)
					++cnt[j];
			}
		}
	}

	cout << cnt[0] << "\n" << cnt[1];

	return 0;
}