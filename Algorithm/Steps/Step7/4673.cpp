#include <iostream>
using namespace std;

#define N 10001
bool arr[N]; // ¼¿ÇÁ³Ñ¹ö true , ¼¿ÇÁ³Ñ¹öX false

inline int dn(int n) {
	int num = 0;
	int m = n;

	while (n != 0) {
		num += n % 10;
		n = n / 10;
	}
	num = m + num;
	return num;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < N; ++i) {
		arr[i] = true;
	}

	int idx;
	for (int i = 0; i < N; ++i) {
		idx = dn(i);
		if (idx < N) {
			arr[idx] = false;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (arr[i] == true) {
			cout << i << '\n';
		}
	}

	return 0;
}