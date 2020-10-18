#include <iostream>
#include <algorithm>
using namespace std;

int alpha[31];
int d[31];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	for (int i = 2; i <= n; ++i) {
		d[i] = d[i - 2];
	}

	printf("Hello world\n");
	cout << "Hello world");

	return 0;
}