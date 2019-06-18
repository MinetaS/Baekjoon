#include <cstdio>
#include <cmath>

int main() {
	unsigned long long n;

	scanf("%llu", &n);
	printf("%.8Lf", sqrtl((long double)n)*4.0L);

	return 0;
}