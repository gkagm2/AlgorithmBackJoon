#pragma warning(disable:4996)
#include <iostream>
#include <time.h>

int main(void) {
	struct tm *t;
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);

	char s[30];
	sprintf(s, "%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	printf("%s\n", s);
	return 0;
}
