#include <cstdio>
#include <cstring>
#include <cmath>

bool prime[10001];

int main() {
	memset(prime, 1, sizeof(prime));
	prime[1] = 0;

	for (int i=2 ; i<=(int)sqrt(10001.0f) ; i++) {
		if (!prime[i]) continue;

		for (int j=i*2 ; j<=10001 ; j+=i)
			prime[j] = false;
	}

	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n;

		scanf("%d", &n);

		if (n == 4) {
			printf("2 2\n");
			continue;
		}

		int last = -1;

		for (int i=3 ; i<=n/2 ; i+=2)
			if (prime[i] && prime[n-i]) last = i;
		

		printf("%d %d\n", last, n-last);
	}

	return 0;
}