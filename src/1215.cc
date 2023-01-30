#include <cstdio>

#define min(x, y) (((x) < (y)) ? (x) : (y))

typedef long long int64_t;

int64_t sum(int64_t a, int64_t d, int64_t n) {
	return (2*a-d*n)*(n+1)/2;
}

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	int i = 1;
	int64_t r = 0;

	while (i <= n) {
		int q = k%i;
		int p = k/i;
		int a = (p > 0) ? q/p : 2147483647;
		r += sum(q, p, min(a, n-i));
		i += min(a, n-i)+1;
	}

	printf("%lld", r);

	return 0;
}