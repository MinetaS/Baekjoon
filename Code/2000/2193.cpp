#include <cstdio>

unsigned long long cache[91] = {0,};

int main() {
	int n;

	scanf("%d", &n);
	cache[1] = 1;

	for (int i=2 ; i<=n ; i++)
		cache[i] = cache[i-1]+cache[i-2];

	printf("%llu", cache[n]);

	return 0;
}