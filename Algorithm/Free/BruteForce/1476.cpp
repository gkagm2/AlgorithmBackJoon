#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int e, s, m;
	
	cin >> e >> s >> m;
	int E, S, M;
	E = S = M = 1;
	int i = 1;
	while (true) {
		if (e == E && s == S && m == M)
		{
			cout << i;
			break;
		}

		++E;
		++S;
		++M;
		if (E == 16)
			E = 1;
		if (S == 29)
			S = 1;
		if (M == 20)
			M = 1;
		++i;
	}

	return 0;
}