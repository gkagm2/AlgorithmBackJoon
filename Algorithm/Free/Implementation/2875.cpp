#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int girl, man, k;
	int teamCnt = 0;

	cin >> girl >> man >> k;
	
	while (true) {
		girl -= 2;
		man -= 1;

		if (0 > girl || 0 > man || girl + man < k)
			break;
		++teamCnt;
	}
	cout << teamCnt;
		
	return 0;
}