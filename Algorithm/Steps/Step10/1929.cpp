// 12ms 2960KB O(NLogLogN)
#include <iostream>
using namespace std;

bool check[1000001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// 에라토스테네스의 체
	check[0] = check[1] = true;

	for (int i = 2; i * i <= 1000000; ++i) {
		if (check[i] == false) {
			for (int j = i + i; j <= 1000000; j += i) {
				check[j] = true;
			}
		}
	}

	int n, m;
	int cnt = 0;
	cin >> m >> n;

	for (int i = m; i <= n; ++i) {
		if (check[i] == false) {
			cout << i << "\n";
		}
	}

	return 0;
}

/*/
#include <iostream>
#include <cstring>
using namespace std;

// 내가 짠 Script. 속도 16ms, 메모리 2840KB
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	bool numbers[1000001] = { false, false };
	memset(numbers, 1, 1000001);
	numbers[0] = numbers[1] = true;

	for (int i = 2; i < 1000001; i++) {
		if (numbers[i] == true) {
			for (int j = 2; i*j < 1000001; j++) {
				numbers[i*j] = false;
			}
		}
	}

	int input1, input2;
	cin >> input1 >> input2;

	for (int i = input1; i <= input2; ++i) {
		if (numbers[i] == true) {
			cout << i << '\n';
		}
	}

	return 0;
}
*/

// 속도 8ms, 메모리 1988KB
//#include <cmath>
//#include <cstdio>
//#include <cstring>
//
//// 0 : prime, 1 : composite
//static unsigned char sieve[125000];
//
//static inline bool isComposite(int x) {
//	return sieve[x >> 3] & (1 << (x & 7));
//}
//
//static inline void setComposite(int x) {
//	sieve[x >> 3] |= 1 << (x & 7);
//}
//
//int main() {
//	int M, N, sqRoot;
//	char input[1 << 15];
//
//	scanf_s("%d %d", &M, &N);
//
//	setvbuf(stdout, input, _IOFBF, sizeof(input));
//
//	sqRoot = (int)sqrt((double)N);
//
//	for (int i = 3; i <= sqRoot; i += 2) {
//		if (!isComposite(i))
//			for (int j = i * i; j <= N; j += i)
//				setComposite(j);
//	}
//
//	if (M <= 2) {
//		if (N >= 2)
//			printf("2\n");
//		M = (M == 1) ? M + 2 : M + 1;
//	}
//
//	for (int i = (M % 2 == 0) ? M + 1 : M; i <= N; i += 2)
//		if (!isComposite(i))
//			printf("%d\n", i);
//
//	return 0;
//}