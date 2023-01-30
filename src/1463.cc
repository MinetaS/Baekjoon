#include <cstdio>
#include <malloc.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))

int *cache;

int search(int, int);

int main() {
	int n;

	scanf("%d", &n);
	cache = (int *)calloc(n+1, sizeof(int));
	cache[1] = 0;

	for (int i=2 ; i<=n ; i++) {
		int r = 2147483647;

		if (i%3 == 0) r = min(cache[i/3], r);
		if (i%2 == 0) r = min(cache[i/2], r);
		r = min(cache[i-1], r) + 1;

		cache[i] = r;
	}
	
	printf("%d", cache[n]);

	return 0;
}