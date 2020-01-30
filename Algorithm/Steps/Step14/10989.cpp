#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 10001

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt;
	cin >> cnt;

	int countingArr[MAX_SIZE];
	memset(countingArr, 0, sizeof(countingArr));

	int n;
	for (int i = 0; i < cnt; ++i) {
		cin >> n;
		++countingArr[n];
	}

	for (int i = 0; i < MAX_SIZE; ++i) {
		while (countingArr[i]) {
			cout << i << ' ';
			--countingArr[i];
		}
	}

	return 0;
}