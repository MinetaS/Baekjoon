#include <cstdio>

int main() {
	int n;
	unsigned long long r = 1;

	scanf("%d", &n);

	for (int i=1 ; i<=n ; i++)
		r *= i;

	printf("%llu", r);

	return 0;
}