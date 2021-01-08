#include <stdio.h>
using namespace std;

int main() {

	int cnt = 0;
	int n;

	while (scanf("%d", &n) != EOF) {
		if (n > 0)
			++cnt;
	}

	printf("%d", cnt);
	return 0;
}