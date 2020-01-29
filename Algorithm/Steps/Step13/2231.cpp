#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int cnt = 0, minNum;

	cin >> n;

	// 자릿수를 구한다.
	minNum = n;
	while (minNum) {
		minNum = minNum / 10;
		++cnt; 
	}

	minNum = n - cnt * 9; // 각 자릿수의 최대 숫자는 9임. 범위를 구함

	int answer = n;

	for (int generator = minNum; generator < n; ++generator) {
		int temp = generator;
		int sum = 0;
		while (temp) {
			sum = sum + temp % 10;
			temp = temp / 10;
		}

		if (sum + generator == n) {
			if (answer > generator) {
				answer = generator;
			}
		}
	}

	if (answer == n) {
		cout << 0;
	}
	else {
		cout << answer;
	}

	return 0;
}