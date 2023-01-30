#include <cstdio>
#include <cstring>

#define MOD 10007

int cache[1001][1001];

int binomial(int, int, int);

int main() {
	int n, k;

	scanf("%d %d", &n, &k);
	memset(cache, -1, sizeof(cache));

	printf("%d", binomial(n, k, MOD));

	return 0;
}

int binomial(int n, int k, int mod=2147483647) {
	if (cache[n][k] != -1) return cache[n][k];
	
	if (k == n) return 1;
	if (k == 0) return 1;

	return cache[n][k]=(binomial(n-1, k, mod)%mod+binomial(n-1, k-1, mod)%mod)%mod;
}