#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string g_str[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

inline int GetValue(string _keyWord) {
	for (int i = 0; i < 10; ++i) {
		if(_keyWord == g_str[i])
			return i;
	}
	return -1;
}
inline long long GetMul(int _num) {
	if (_num == 0)
		return 1;
	return pow(10, _num);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string col[3];

	cin >> col[0] >> col[1] >> col[2];
	cout << (GetValue(col[1]) + GetValue(col[0]) * 10) * GetMul((GetValue(col[2])));
	return 0;
}