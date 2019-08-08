#include <cstdio>
#include <cmath>

int main() {
	int n, sq;

	scanf("%d", &n);

	if (n == 1) return 0;

	sq = (int)sqrt(n);

	for (int i=2 ; i<=sq ; i++) {
		while (n%i == 0) {
			printf("%d\n", i);
			n /= i;
		}
	}

	if (n != 1) printf("%d\n", n);

	return 0;
}