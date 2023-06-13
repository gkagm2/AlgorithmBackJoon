#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	float h, w, n, m;

	cin >> h >> w >> n >> m;
	
	int wCnt = int(ceil(h / (n + 1)));
	int hCnt = int(ceil(w / (m + 1)));

	cout << wCnt * hCnt;


	return 0;
}