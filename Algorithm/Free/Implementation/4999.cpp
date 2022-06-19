#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string j;
	string d;
	cin >> j;
	cin >> d;

	if (j.size() >= d.size())
		cout << "go";
	else
		cout << "no";

	return 0;
}