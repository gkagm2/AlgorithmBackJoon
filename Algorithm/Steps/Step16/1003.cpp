#include <iostream>
using namespace std;

// DP solving
int arr[41];

inline void FibonacciArrSetting() {

	// setting
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= 40; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCnt, n;
	int zeroCnt, oneCnt;
	cin >> testCnt;

	FibonacciArrSetting();

	while (testCnt--) {
		cin >> n;
		zeroCnt = oneCnt = 0;
		
		if (n == 0) {
			cout << "1 0\n";
		}
		else {
			zeroCnt = arr[n - 1];
			oneCnt = arr[n];
			cout << zeroCnt << ' ' << oneCnt << '\n';
		}
	}

	return 0;
}


// Recursive solving (time over)

//inline int Fibonacci(int n) {
//	if (n == 0) {
//		++zeroCnt;
//		return 0;
//	}
//	else if (n == 1) {
//		++oneCnt;
//		return 1;
//	}
//	else {
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//}