#include <iostream>
#include <string>
using namespace std;


int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int num[10] = {4,2,3,3,3,3,3,3,3,3};

	string input;
	while (true) {
		cin >> input;
		if (input == "0")
			break;
		int space = 0;
		for (int i = 0; i < input.size(); ++i) {
			int n = input[i] - '0';
			space += num[n] + 1;
		}
		++space;
		cout << space<< "\n";
	}
	
	return 0;
}