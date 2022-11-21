#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	for (int i = 1; i <= n; ++i) {
		string str;
		getline(cin, str);
		cout << i << ". " << str <<"\n";
	}

	return 0;
}