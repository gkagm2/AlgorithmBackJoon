#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

inline bool Compare(string& a, string& b) {
	return a < b ? true : false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	list<string> l;
	string str;

	cin >> str;

	string part;
	int length = str.length();
	
	for (int i = 0; i < str.length(); ++i) {
		part = str.substr(i, length);
		l.push_back(part);
	}

	l.sort(Compare);

	auto begin = l.begin();
	auto end = l.end();


	for (auto i = begin; i != end; ++i) {
		cout << *i << '\n';
	}
		
	return 0;
}