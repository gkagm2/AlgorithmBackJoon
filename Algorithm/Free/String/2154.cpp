#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str = "";
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		str += to_string(i);

	int idx;
	idx = str.find(to_string(n));
	cout << idx + 1;

	return 0;
}