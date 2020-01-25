#include <iostream>
using namespace std;

inline int Fibonacci(int num) {
	 if(num > 2)
		return Fibonacci(num - 1) + Fibonacci(num - 2);
	 else if (num == 0)
		 return 0;
	 else if (num == 1 || num == 2)
		 return 1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	cout << Fibonacci(num);

	return 0;
}