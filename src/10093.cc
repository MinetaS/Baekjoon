#include <cstdio>
#include <algorithm>

typedef unsigned long long uint64_t;

int main() {
	uint64_t a, b;

	scanf("%llu %llu", &a, &b);
	if (a > b) std::swap(a, b);

	printf("%llu\n", (a==b) ? 0 : b-a-1);

	for (uint64_t i=a+1 ; i<=b-1 ; i++)
		printf("%llu ", i);

	return 0;
}