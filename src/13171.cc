#include <cstdio>

#define MOD 1000000007

typedef unsigned long long uint64_t;

uint64_t power(uint64_t, uint64_t);

int main() {
	uint64_t n, r;

	scanf("%llu\n%llu", &n, &r);
	printf("%llu", power(n, r));

	return 0;
}

uint64_t power(uint64_t n, uint64_t r) {
	if (r == 0) return 1;
	if (r == 1) return n%MOD;
	if (r & 0x1) return ((n%MOD)*power(n, r-1))%MOD;
	else return (power(n, r/2)*power(n, r/2))%MOD;
}