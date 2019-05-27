#include <cstdio>

typedef unsigned long long uint64_t;

int popcnt64(uint64_t);

int main() {
	uint64_t mod = 0;
	int t;
	
	for (int i=0 ; i<10 ; i++) {
		scanf("%d", &t);
		mod |= 1uLL << (t%42);
	}

	printf("%d", popcnt64(mod));

	return 0;
}

int popcnt64(uint64_t x) {
	const uint64_t m1  = 0x5555555555555555;
	const uint64_t m2  = 0x3333333333333333;
	const uint64_t m4  = 0x0f0f0f0f0f0f0f0f;
	const uint64_t h01 = 0x0101010101010101;

	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	return (x * h01) >> 56;
}