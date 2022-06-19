#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	long long num;
	string result = "";

	cin >> num;

	while (num != 0) {
		int r = num % 2;
		result = to_string(r) + result; 
		num = num / 2;
	}
	cout << result;

	return 0;
}