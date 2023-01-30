#include <cstdio>

typedef unsigned long long uint64_t;

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int k, n;
		uint64_t res = 1;

		scanf("%d\n%d", &k, &n);
		k += 1;
		n -= 1;

		if (k < n) {
			int _t = k;
			k = n;
			n = _t;
		}

		for (int i=k+1 ; i<=n+k ; i++)
			res *= i;

		for (int i=1 ; i<=n ; i++)
			res /= i;

		printf("%llu\n", res);
	}

	return 0;
}