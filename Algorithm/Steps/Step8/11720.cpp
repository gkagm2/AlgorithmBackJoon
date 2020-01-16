#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count;
	
	char number[1024] = {};
	int sum = 0;

	cin >> count;
	cin.ignore(1024, '\n');
	cin.getline(number, count+1);

	for (int i = 0; i < count; ++i) {
		
		sum += (int)number[i] - '0';
	}

	cout << sum;

	return 0;
}