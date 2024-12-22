#include <iostream>
#include <vector>
using namespace std;

void PrintStar(int _cnt) {
	for (int i = 0; i < _cnt; ++i)
		cout << "*";
}

void PrintSpace(int _cnt) {
	for (int i = 0; i < _cnt; ++i)
		cout << " ";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	vector<int> v1, v2;

	int n;
	cin >> n;
	for (int i = n; i > 0; --i) {
		int cnt = 1 + 2 * (i - 1);
		int spcnt = n - i;
		PrintSpace(spcnt);
		PrintStar(cnt);
		v1.push_back(cnt);
		v2.push_back(spcnt);
		if(i != 0)
			cout << "\n";
	}
	for (int i = v1.size() - 2; i >= 0; --i) {
		PrintSpace(v2[i]);
		PrintStar(v1[i]);
		cout << "\n";
	}

	return 0;
}