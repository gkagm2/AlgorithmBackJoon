#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string caesar;
	string origin;
	cin >> caesar;
	origin.resize(caesar.size());

	for (int i = 0; i < caesar.size(); ++i) {
		char o = caesar[i];
		if (o < 'D')
			o = o - 'C' + 'Z';
		else
			o = o - 'D' + 'A';
		origin[i] = o;
	}

	cout << origin;

	return 0;
}