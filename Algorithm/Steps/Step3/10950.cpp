#include <stdio.h>
// cin cout으로 사용했을 경우 : 메모리 1984KB, 시간 4ms
// scanf printf로 사용했을 경우 : 메모리 1112KB, 시간 0ms
int main() {

	int count;
	int a, b;
	int i;
	scanf("%d", &count);

	for ( i = 0; i < count; ++i) {
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", a + b);
	}

	return 0;
}