#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define beforeChar char
#define afterChar char

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	unordered_map<beforeChar, afterChar> m;

	m['.'] = '.';
	m['O'] = 'O';
	m['-'] = '|';
	m['|'] = '-';
	m['/'] = '\\';
	m['\\'] = '/';
	m['^'] = '<';
	m['<'] = 'v';
	m['v'] = '>';
	m['>'] = '^';


	vector<vector<char>> v;
	int w, h;
	cin >> h >> w;

	v.resize(h);
	for (int i = 0; i < v.size(); ++i)
		v[i].resize(w);

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			char input;
			cin >> input;
			v[y][x] = input;
		}
	}

	// Rendering
	for (int x = w - 1; x >= 0; --x) {
		for (int y = 0 ; y < h; ++y) {
			cout << m[v[y][x]];
		}
		cout << "\n";
	}

	return 0;
}
