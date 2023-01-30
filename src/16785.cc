#include <cstdio>

int main() {
	int a, b, c;
	int day = 0;

	scanf("%d %d %d", &a, &b, &c);

	day += (c/(7*a+b))*7;
	c %= 7*a+b;
	c = (c > 7*a) ? 7*a : c;
	if (c != 0) day += (c-1)/a+1;

	printf("%d", day);

	return 0;
}