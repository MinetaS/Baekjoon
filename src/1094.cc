#include <cstdio>

#ifdef _MSC_VER
#include <intrin.h>
#define bit_count __popcnt
#else
#define bit_count __builtin_popcount
#endif

int main() {
	unsigned int n;

	scanf("%u", &n);
	printf("%d", bit_count(n));

	return 0;
}