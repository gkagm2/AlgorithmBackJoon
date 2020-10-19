#include <iostream>
#include <string.h>
using namespace std;

char bitA[100001];
char bitB[100001];
char ans[100001];

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> bitA;
	cin >> bitB;

	int len = strlen(bitA);

	// A & B
	for (int i = 0; i < len; ++i)
		ans[i] = bitA[i] & bitB[i];
	cout << ans << "\n";

	// A | B
	for (int i = 0; i < len; ++i)
		ans[i] = bitA[i] | bitB[i];
	cout << ans << "\n";

	// A ^ B
	for (int i = 0; i < len; ++i)
		ans[i] = bitA[i] == bitB[i] ? '0' : '1';
	cout << ans << "\n";

	// ~A
	for (int i = 0; i < len; ++i)
		ans[i] = bitA[i] == '0' ? '1' : '0';
	cout << ans << "\n";

	// ~B
	for (int i = 0; i < len; ++i)
		ans[i] = bitB[i] == '0' ? '1' : '0';
	cout << ans << "\n";

	return 0;
}