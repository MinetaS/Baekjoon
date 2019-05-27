#include <cstdio>
#include <cstring>
#include <cmath>

bool prime[1000001];

int main() {
	int m, n;

	scanf("%d %d", &m, &n);
	memset(prime, 1, sizeof(prime));

	prime[1] = false;

	for (int i=2 ; i<=(int)sqrt((double)n) ; i++) {
		if (!prime[i]) continue;

		for (int j=i*2 ; j<=n ; j+=i)
			prime[j] = false;

	}

	for (int i=m ; i<=n ; i++)
		if (prime[i]) printf("%d\n", i);

	return 0;
}