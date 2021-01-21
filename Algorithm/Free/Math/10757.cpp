#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	
	int aSize = a.size();
	int bSize = b.size();

	if (aSize < bSize) {
		string t = a;
		a = b;
		b = t;
		int ti;
		ti = aSize;
		aSize = bSize;
		bSize = ti;
	}
	
	string result = "";
	int song = 0;
	int temp;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (int i = 0; i < aSize; ++i) {
		if (i >= bSize)
			temp = a[i] - '0' + song;
		else
			temp = (b[i] - '0') + (a[i] - '0') + song;
		song = temp / 10;
		result = to_string(temp % 10) + result;
	}
	if (song != 0)
		result = to_string(song) + result;
	cout << result;

	return 0;
}