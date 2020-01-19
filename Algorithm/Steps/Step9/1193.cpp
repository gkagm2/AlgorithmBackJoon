// 나름 생각해서 푼 것.. 속도가 안나온다.
#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool pattern = true;
	int num, x, y;
	int maxNum = 0;
	x = y = 0;

	cin >> num;

	while (num > 1) {
		if (maxNum == y && pattern) {
			pattern = false;
			++maxNum;
			++y;
		}
		else if (maxNum == x && !pattern) {
			pattern = true;
			++maxNum;
			++x;
		}
		else if (pattern) {
			--x;
			++y;
		}
		else if(!pattern) {
			++x;
			--y;
		}
		--num;
	}
	cout << x + 1 << "/" << y + 1 << endl;

	return 0;
}

// 최고의 답
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	int x;
//	scanf_s("%d", &x);
//
//	while (x > 0)
//	{
//		num++;
//		x -= num;
//	}
//	if (num % 2 == 0)
//		printf("%d/%d", num + x, 1 - x);
//	else
//		printf("%d/%d", 1 - x, num + x);
//
//	return 0;
//}