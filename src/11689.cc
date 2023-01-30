#include <cstdio>

typedef unsigned long long uint64;

int main() {
	uint64 n, r;

	scanf("%llu", &n);
	r = n;

	for (uint64 p=2 ; p*p<=n ; p++) {
		if (n%p == 0) {
			while (n%p == 0) n/=p;
			r -= r/p;
		}
	}

	if (n > 1) r -= r/n;

	printf("%llu", r);

	return 0;
}