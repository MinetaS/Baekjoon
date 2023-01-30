#include <cstdio>
#include <cstring>
#include <cmath>

bool prime[246913];

int main() {
	memset(prime, 1, sizeof(prime));
	prime[1] = 0;

	for (int i=2 ; i<=(int)sqrt(246912.0f) ; i++) {
		if (!prime[i]) continue;

		for (int j=i*2 ; j<=246912 ; j+=i)
			prime[j] = false;
	}

	while (true) {
		int n;
		int c = 0;

		scanf("%d", &n);

		if (n == 0) break;

		for (int i=n+1 ; i<=2*n ; i++)
			if (prime[i]) c++;

		printf("%d\n", c);
	}

	return 0;
}