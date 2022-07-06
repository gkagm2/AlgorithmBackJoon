#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string name;
	string answer = "";

	cin >> name;

	for (int i = 0; i < name.size(); ++i) {
		if (name[i] >= 'A' && name[i] <= 'Z')
			answer += name[i];
	}

	cout << answer;

	return 0;
}