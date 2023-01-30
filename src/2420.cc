#include <stdio.h>

int main() {
	long long x, y;

	scanf("%lld %lld", &x, &y);

	printf("%lld", ((x>y) ? x-y : y-x));

	return 0;
}