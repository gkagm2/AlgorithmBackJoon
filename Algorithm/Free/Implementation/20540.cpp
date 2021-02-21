#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	map<char, char> m;

	m.insert(make_pair('E','I'));
	m.insert(make_pair('S', 'N'));
	m.insert(make_pair('T', 'F'));
	m.insert(make_pair('J', 'P'));
	m.insert(make_pair('I', 'E'));
	m.insert(make_pair('N', 'S'));
	m.insert(make_pair('F', 'T'));
	m.insert(make_pair('P', 'J'));

	char str[5];
	cin >> str;

	for (int i = 0; i < 4; ++i)
		cout << m[str[i]];

	return 0;
}