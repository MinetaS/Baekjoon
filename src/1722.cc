#include <cstdio>

typedef long long int64;

int main() {
	constexpr int64 factorial[20] = {1LL, 1LL, 2LL, 6LL, 24LL, 120LL, 720LL, 5040LL, 40320LL, 362880LL, 3628800LL, 39916800LL, 479001600LL, 6227020800LL, 87178291200LL, 1307674368000LL, 20922789888000LL, 355687428096000LL, 6402373705728000LL, 121645100408832000LL};
	int n;
	int id;
	bool used[20] = {false,};

	scanf("%d", &n);
	scanf("%d", &id);

	if (id == 1) {
		int64 k;
		
		scanf("%lld", &k);
		k -= 1;

		for (int i=1 ; i<=n ; i++) {
			int count = 0;

			while (used[count]) count++;

			while (k-factorial[n-i] >= 0) {
				k -= factorial[n-i];
				do {count++;} while (used[count]);
			}

			printf("%d ", count+1);
			used[count] = true;
		}
	}

	if (id == 2) {
		int64 k = 0;

		for (int t, i=1 ; i<=n ; i++) {
			int count = 0;

			scanf("%d", &t);

			for (int j=1 ; j<t ; j++)
				if (!used[j-1]) count++;

			used[t-1] = true;
			k += count*factorial[n-i];
		}

		printf("%lld", k+1);
	}

	return 0;
}