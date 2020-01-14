#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	
	bool restCheckArr[42]{ false, };

	for (int i = 0; i < 10; ++i) {
		cin >> num;
		restCheckArr[num % 42] = true;
	}

	int restCount = 0;

	for (int i = 0; i < 42; ++i) {
		if (restCheckArr[i] == true) {
			++restCount;
		}
	}
	cout << restCount;

	return 0;
}