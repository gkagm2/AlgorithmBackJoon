#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numCountArr[10] = { 0, }; // index 0은 0의 총 개수, index 1은 1의 개수 총 개수 ...
	int a, b, c;

	cin >> a >> b >> c;

	int iMul = a * b * c;
	int index;

	while (iMul != 0) {
		index = iMul % 10;
		++numCountArr[index];
		iMul = iMul / 10;
	}

	for (int i = 0; i < 10; ++i) {
		cout << numCountArr[i] << '\n';
	}

	return 0;
}