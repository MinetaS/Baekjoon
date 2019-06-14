#include <cstdio>

int main() {
	int n, r;
	
	while (true) {
		scanf("%d", &n);

		if (n == 0) break;

		r = n;

		for (int p=2 ; p*p<=n ; p++) {
			if (n%p == 0) {
				while (n%p == 0) n/=p;
				r -= r/p;
			}
		}

		if (n > 1) r -= r/n;

		printf("%d\n", r);
	}

	return 0;
}