#include <cstdio>
#include <cstring>

#define MOD 10007

int fill(int);

int cache[1001];

int main() {
	int n;

	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));

	printf("%d", fill(n));

	return 0;
}

int fill(int width) {
	if (width <= 1) return 1;
	if (cache[width] != -1) return cache[width];

	return cache[width] = (fill(width-2)*2 + fill(width-1))%MOD;
}