#include <iostream>
using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int count;
	cin >> count;
	int a, b;

	for (int i = 1; i <= count; ++i){
		cin >> a;
		cin >> b;
		cout << "Case #" << i << ": " << a + b << '\n';
	}

	return 0;
}