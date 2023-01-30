#include <cstdio>
#include <cmath>

typedef unsigned long long uint64_t;

bool sqr[1000001] = {0,};

int main() {
	uint64_t m, n, c;

	scanf("%llu %llu", &m, &n);

	for (uint64_t i=2 ; i*i<=n ; i++) {
		uint64_t _s = (m-1)/(i*i)+1;

		for (uint64_t j=_s ; i*i*j<=n ; j++)
			sqr[i*i*j-m] = true;
	}

	c = 0;

	for (uint64_t i=0 ; i<n-m+1 ; i++)
		if (!sqr[i]) c++;
	
	printf("%llu", c);

	return 0;
}