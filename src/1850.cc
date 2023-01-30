#include <stdio.h>

typedef unsigned long long uint64_t;

uint64_t gcd(uint64_t, uint64_t);

int main() {
	uint64_t m, n;

	scanf("%llu %llu", &m, &n);
		
	for (uint64_t i=0 ; i<gcd(m, n) ; i++)
		printf("1");

	return 0;
}

uint64_t gcd(uint64_t x, uint64_t y) {
	uint64_t _x, _y;
	if (x > y) { _x=x; _y=y; }
	else { _x=y; _y=x; }

	if (_x%_y == 0) return _y;

	return gcd(_y, _x%_y);
}