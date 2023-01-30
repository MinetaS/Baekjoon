#include <cstdio>
#include <cstring>

int cache[46];

int fibonacci(int);

int main() {
	int n;

	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	cache[0] = 0;
	cache[1] = 1;

	printf("%d %d", fibonacci(n-1), fibonacci(n));

	return 0;
}

int fibonacci(int n) {
	if (cache[n] != -1) return cache[n];
	return cache[n] = fibonacci(n-1)+fibonacci(n-2);
}