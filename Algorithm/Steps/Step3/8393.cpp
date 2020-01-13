#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	// num의 숫자가 높아질수록 for문으로 돌리면 속도가 느려짐.
	cout << num * (num + 1) / 2;

	return 0;
}