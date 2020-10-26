#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int mType[] = {500, 100,50,10,5,1 };
	int money, i = 0, cnt = 0;
	cin >> money;

	money = 1000 - money;

	while (money > 0) {
		cnt += money / mType[i];
		money %= mType[i];
		++i;
	}

	cout << cnt;

	return 0;
}