#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	int kim, imm;
	int cnt = 0;
	cin >> n >> kim >> imm;

	while (kim != imm) {
		kim = kim++ / 2;
		imm = imm++ / 2;
		cnt++;
	}

	cout << cnt;
	return 0;
}