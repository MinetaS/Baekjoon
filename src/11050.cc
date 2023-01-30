#include <cstdio>
#include <cstring>

int cache[11][11];

int binomial(int, int);

int main() {
	int n, k;

	scanf("%d %d", &n, &k);
	memset(cache, -1, sizeof(cache));

	printf("%d", binomial(n, k));

	return 0;
}

int binomial(int n, int k) {
	if (cache[n][k] != -1) return cache[n][k];

	if (k == n) return 1;
	if (k == 0) return 1;

	return cache[n][k]=binomial(n-1, k)+binomial(n-1, k-1);
}