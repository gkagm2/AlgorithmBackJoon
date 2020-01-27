#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int line;
	cin >> line;

	for (int i = 3; i <= line; i += 3) {
		switch (i % 18) {
		case 3: case 9:
			cout << "***************************" << '\n';
			cout << "* ** ** ** ** ** ** ** ** *" << '\n';
			cout << "***************************" << '\n';
			break;
		case 6:
			cout << "***   ******   ******   ***" << '\n';
			cout << "* *   * ** *   * ** *   * *" << '\n';
			cout << "***   ******   ******   ***" << '\n';
			break;
		case 0: case 12:
			cout << "*********         *********" << '\n';
			cout << "* ** ** *         * ** ** *" << '\n';
			cout << "*********         *********" << '\n';
			break;
		case 15:
			cout << "***   ***         ***   ***" << '\n';
			cout << "* *   * *         * *   * *" << '\n';
			cout << "***   ***         ***   ***" << '\n';
			break;
		}
	}

	return 0;
}