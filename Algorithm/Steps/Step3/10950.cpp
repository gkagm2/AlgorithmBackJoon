#include <stdio.h>
// cin cout���� ������� ��� : �޸� 1984KB, �ð� 4ms
// scanf printf�� ������� ��� : �޸� 1112KB, �ð� 0ms
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