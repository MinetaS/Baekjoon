#include <cstdio>

int main() {
	long long a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);

	long double r1 = (long double)(a*c)/b;
	long double r2 = (long double)(a*b)/c;

	printf("%d", (int)((r1 > r2) ? r1 : r2));

	return 0;
}