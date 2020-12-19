#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int cnt = 1;
	string s;
	
	while (getline(cin, s, '\n')) {
		if (s == "Was it a cat I saw?")
			break;

		for (int i = 0; i < s.size(); i = i + cnt + 1) {
			cout << s[i];
		}
		cout << "\n";
		cnt++;
	}

	return 0;
}