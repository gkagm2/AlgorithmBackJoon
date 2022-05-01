#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int S[21] = {};
	int cnt;
	string command;

	cin >> cnt;
	while (cnt--) {
		int num;
		cin >> command;
		
		if ("add" == command) {
			cin >> num;
			S[num] = 1;
		}
		else if ("remove" == command) {
			cin >> num;
			S[num] = 0;
		}
		else if ("check" == command) {
			cin >> num;
			if (S[num] == 0)
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if ("toggle" == command) {
			cin >> num;
			S[num] = 0 == S[num] ? 1 : 0;
		}
		else if ("all" == command) {
			for (int i = 1; i <= 20; ++i)
				S[i] = 1;
		}
		else if ("empty" == command) {
			for (int i = 1; i <= 20; ++i)
				S[i] = 0;
		}
	}

	return 0;
}