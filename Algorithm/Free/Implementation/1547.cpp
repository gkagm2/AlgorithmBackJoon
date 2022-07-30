#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
	int t;
	t = a;
	a = b; 
	b = t;
}

int FindCupIdx(int* cups, int cnt, int num) {
	for (int i = 0; i < cnt; ++i) {
		if (cups[i] == num)
			return i;
	}
	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int cups[3] = { 1, 2, 3 };

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		int cup1Idx = FindCupIdx(cups, 3, n1);
		int cup2Idx = FindCupIdx(cups, 3, n2);
		Swap(cups[cup1Idx], cups[cup2Idx]);
	}
	int num = cups[0];

	cout << num;
	return 0;
}