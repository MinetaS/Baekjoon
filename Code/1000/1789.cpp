#include <cstdio>

typedef unsigned long long uint64_t;

int main() {
	unsigned int s;

	scanf("%u", &s);

	for (uint64_t i=1 ; i<=92682 ; i++) {
		uint64_t sum = i*(i+1)/2;
		if (sum > s) {
			printf("%llu", i-1);
			break;
		}
	}

	return 0;
}