#include <iostream>
#include <cstring>
using namespace std;

int d[100001][3];

// Bottom up
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	d[0][0] = 1;
	
	for (int i = 1; i <= n; ++i) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 9901;
	}

	cout << (d[n][0] + d[n][1] + d[n][2]) % 9901;

	return 0;
}